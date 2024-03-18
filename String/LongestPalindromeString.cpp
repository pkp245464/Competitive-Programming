#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double  
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = (int)s.size(),mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            string w = s.substr(i, j - i + 1);
            string u(w.rbegin(), w.rend());
            if (w == u) {
                mx = max(mx,(int)w.size());
            }
        }
    }
    cout << mx << nl;
    return 0;   
}
