#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void count_sort(vector<int>&p,vector<int>&c) {
    int n = p.size();
    vector<int>cnt(n);
    for(auto &it : c) {
        cnt[it]++;
    }
    vector<int>tmp(n);
    vector<int>pos(n);
    pos[0] = 0;
    for(int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for(auto it : p) {
        int x = c[it];
        tmp[pos[x]] = it;
        pos[x]++;
    }
    p = tmp; 
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int>p(n),c(n);
    {
        vector<pair<char,int>>a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {s[i],i};
        }
        sort(a.begin(),a.end());
        for(int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for(int i = 1; i < n; i++) {
            if(a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            }
            else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    int k = 0;
    while((1 << k) < n) {
        for(int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        count_sort(p,c);
        vector<int>tmp(n);
        tmp[p[0]] = 0;
        for(int i = 1; i < n; i++) {
            pair<int,int>prev = {c[p[i - 1]],c[(p[i-  1] + (1 << k)) % n]};
            pair<int,int>cur = {c[p[i]],c[(p[i] + (1 << k)) % n]};
            if(prev == cur) {
                tmp[p[i]] = tmp[p[i - 1]];
            }
            else {
                tmp[p[i]] = tmp[p[i - 1]] + 1;
            }
        }
        c = tmp;
        k++;
    }
    vector<int>lcp(n);
    k = 0;
    for(int i = 0; i < n - 1; i++) {
        int pi = c[i];
        int j = p[pi - 1];
        while(s[i + k] == s[j + k]) {
            k++;
        }
        lcp[pi] = k;
        k = max(k - 1,0);
    }
    for(int i = 0; i < n; i++) {
        cout << lcp[i] << " " << p[i] << " " << s.substr(p[i],n - p[i]) << nl;
    }
    return 0;
}