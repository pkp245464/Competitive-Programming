#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
ll MOD = 1e9 + 7;
ll fun(ll n,vector<ll>&dp) {
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    ll curSum = 0;
    for(ll i = 1; i <= 6; i++) {
        curSum += fun(n - i,dp);
        curSum %= MOD;
    }
    dp[n] = curSum;
    return dp[n];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<ll>dp(n + 1,-1);
    cout << fun(n,dp) << nl;
    return 0;
}
