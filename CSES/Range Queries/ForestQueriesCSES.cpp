/*Problem Link - "https://cses.fi/problemset/result/5379740/"*/
#include<bits/stdc++.h>
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
    ll n,q;
    cin >> n >> q;
    vector<vector<ll>>arr(n + 1,vector<ll>(n + 1,0));
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            char c;
            cin >> c;
            arr[i][j] = c == '*';
            arr[i][j] += arr[i][j - 1]; //Prefix sum form rowwise
        }
    }
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            arr[i][j] += arr[i - 1][j]; // Prefix sum column wise
        }
    }
    while(q--) {
        ll posSX,posSY,posEX,posEY;
        cin >> posSX >> posSY >> posEX >> posEY;
        // return ar[ex][ey] - ar[sx-1][ey] - ar[ex][sy-1] + ar[sx-1][sy-1];
        ll ans = arr[posEX][posEY] - arr[posSX - 1][posEY] - arr[posEX][posSY - 1] + arr[posSX - 1][posSY - 1];
        cout << ans << nl;
    }
    return 0; 
}
 
/*
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
 
//Explainations
 
//First rowwise sum operation
0 1 1 1
1 1 2 3
1 2 2 2
1 2 3 4
//Second columnwise sum operation
0 1 1 1
1 2 3 4
2 4 5 6
3 6 8 10
*/