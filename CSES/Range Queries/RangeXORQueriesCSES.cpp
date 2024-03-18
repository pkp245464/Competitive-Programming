/*Problem Link - "https://cses.fi/problemset/task/1650/"*/
#include<bits/stdc++.h>
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
    ll n,q;
    cin >> n >> q;
    vector<ll>arr(n + 1);
    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] ^= arr[i - 1];
    }
    while(q--) {
        ll l,r;
        cin >> l >> r;
        cout << (arr[r] ^ arr[l - 1]) << nl;
    }
    return 0;
}