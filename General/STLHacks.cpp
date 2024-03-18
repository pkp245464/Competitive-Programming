#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	// work like unordered_map<pair<int,int>>um // it is not possible so we can use below method
    unordered_map<bool,unordered_map<int,int>>um;
    um[3][4] = true;
    um[7][8] = false;
    um[4][5] = false;
    um[4][2] = false;
    um[1][2] = true;
    cout <<  "B: " << um[4][5] << nl;
    um[4][5] = true;
    cout <<  "A: " << um[4][5] << nl;
    for(auto it = um.begin(); it != um.end(); it++) {
        auto x = it->second;
        for(auto y : x) {
            cout << y.first << " " << y.second << nl;
        }
    }
    return 0;
}

