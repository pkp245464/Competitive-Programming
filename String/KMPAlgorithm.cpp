//TC : O(n^3)
vector<int> prefix_function(string &s) {
    int n = (int)s.size();
    vector<int>pi(n);
    for(int i = 0; i < n; i++) {
        for(int k = 0; k <= i; k++) {
            if(s.substr(0,k) == s.substr(i - k + 1,k)) {
                pi[i] = k;
            }
        }
    }
    return pi;
}

//TC : O(n)
vector<int> prefix_function(string &s) {
    int n = (int)s.size();
    vector<int>pi(n);
    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
/*
//Knuth–Morris–Pratt algorithm (KMP)
//TC: O(m + n)
//SC: O(m)

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int kmp(string &t, string &p) {
    int m = p.size(), n = t.size();
    p = " " + p;
    vector<int>piTable(m + 1,0);
    int j = 0;
    for(int i = 2; i <= m; i++) {
        while(j <= m && p[j + 1] == p[i]) {
            piTable[i++] = ++j;
        }
        j = 0;
    }
    j = 0;
    for(int i = 0; i < n; i++) {
        if(p[j + 1] != t[i]) {
            while(j != 0 && p[j + 1] != t[i]) {
                j = piTable[j];
            }
        }
        j++;
        if(j == m) {
            return i - m + 1;
        }
  }
  return -1;

}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.t", "r", stdin);
    freopen("output.t", "w", stdout);
#endif
    string t = "pankaj";
    string p = "kaj";
    cout << kmp(t,p) << nl;
    return 0;
}
*/