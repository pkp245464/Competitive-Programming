#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main() {
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,x,MOD = 1e9 + 7;
    cin >> n >> x;
    vector<ll>arr(n),dp(x + 1,0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for(ll i = 0; i < n; i++) {
        for(ll j = 1; j <= x; j++) {
            if(arr[i] <= j) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }
    }
    cout << dp[x] << nl;
    return 0;
}