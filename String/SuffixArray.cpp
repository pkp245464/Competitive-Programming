//TC: O(n(log^2)n)
//using radix_sort TC: O(nlogn)
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void radix_sort(vector<pair<pair<int,int>,int>>&a) {
    int n = a.size();
    {
       vector<int>cnt(n);
        for(auto &it : a) {
            cnt[it.first.second]++;
        }
        vector<pair<pair<int,int>,int>>tmp(n);
        vector<int>pos(n);
        pos[0] = 0;
        for(int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(auto it : a) {
            int x = it.first.second;
            tmp[pos[x]] = it;
            pos[x]++;
        }
        a = tmp; 
    }
    {
        vector<int>cnt(n);
        for(auto &it : a) {
            cnt[it.first.first]++;
        }
        vector<pair<pair<int,int>,int>>tmp(n);
        vector<int>pos(n);
        pos[0] = 0;
        for(int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(auto it : a) {
            int x = it.first.first;
            tmp[pos[x]] = it;
            pos[x]++;
        }
        a = tmp;
    }
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
        vector<pair<pair<int,int>,int>>a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {{c[i],c[(i + (1 << k)) % n]},i};
        }
        //sort(a.begin(),a.end());
		radix_sort(a) //using radix_sort we can optimize the time complexity
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
        k++;
    }
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
		//cout << p[i] << " " << s.substr(p[i],n - p[i]) << nl;

    }
    return 0;
}

/*
I/P: ababba
O/P: 6 5 0 2 4 1 3 
*/


//code optimize

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
    for(int i = 0; i < n; i++) {
        // cout << p[i] << " " << s.substr(p[i],n - p[i]) << nl;
    }
    return 0;
}