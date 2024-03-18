//z_function is used to find the all occurrence of pattern 'p' in string 's'

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//TC: O(n * 2)
vector<int> z_function(string &s) {
    int n = (int)s.size();
    vector<int>z(n);
    for(int i = 1; i < n; i++) {
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
    }
    return z;
}
//TC: O(n)
vector<int> z_function(string &s) {
    int n = s.size();
    vector<int>z(n);
    int l = 0,r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i,z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
int cnt_occurrences(string &s, string &t) {
    string str = t + "$" + s;
    vector<int>z = z_function(str);
    int n = t.size(),ans = 0;
    for(int i = n + 1; i < (int)str.size(); i++) {
        ans += (z[i] == n);
    }
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s,t;
    cin >> s >> t;
    cout << cnt_occurrences(s,t) << nl;
    return 0;
}

/*
I/P: s = abababbab,t = ab
O/P: 2
I/P: s = saippuakauppias,t = pp
O/P: 2

https://cses.fi/problemset/task/1753/
https://cses.fi/problemset/task/1733/
*/