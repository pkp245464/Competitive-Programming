#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
vector<int> rabin_karp(string &pat, string &txt) {
    const int p = 31,mod = 1e9 + 9;
    int n = pat.size(),m = txt.size();

    vector<ll>prePow(max(n,m)); //pre-computing the power 
    prePow[0] = 1;
    for(int i = 1; i < (int)prePow.size(); i++) {
        prePow[i] = (prePow[i - 1] * p) % mod;
    }

    vector<ll>htxt(m + 1, 0); // calculating the hash value of text 
    for (int i = 0; i < m; i++) {
        htxt[i+1] = (htxt[i] + (txt[i] - 'a' + 1) * prePow[i]) % mod; 
    }
    ll hPat = 0; // calculating the hash value of pattern
    for(int i = 0; i < n; i++)  {
        hPat = (hPat + (pat[i] - 'a' + 1) * prePow[i]) % mod; 
    }

    vector<int>ans;
    for(int i = 0; i + n - 1 < m; i++) {
        ll cur = (htxt[i + n] + mod - htxt[i]) % mod; // calculating currrent hash value
        if(cur == hPat * prePow[i] % mod) {
            ans.push_back(i);
        }
    }
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string pat = "kaj",txt = "pankajpankajpankaj";
    vector<int>a = rabin_karp(pat,txt);
    for(int i : a) {
        cout << i << " ";
    }
    return 0;
}

/*
Note: 
where p and m (mod) are some chosen, positive numbers. It is called a polynomial rolling hash function.
string contain lower case p = 31,good choice
string contain upper & lower case p = 53 good choice

Scource - https://cp-algorithms.com/string/string-hashing.html
*/