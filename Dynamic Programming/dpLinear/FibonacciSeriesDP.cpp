#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int n,vector<int>&dp) {
    if(n <= 1) {
        return n;
    } 
    if(dp[n] != -1) {
        return dp[n];
    } 
    return dp[n] = fun(n - 1,dp) + fun(n - 2,dp);
}
int main()  {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 2;
    vector<int>dp(n + 1,-1);
    cout << fun(n,dp) << nl;
    return 0;
}

/*----------------------------------------------------*/
/*----------------------------------------------------*/
/*----------------------------------------------------*/

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
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
    int n = 5;
    vector<int>dp(n + 1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << nl;
    return 0;
}
*/

/*----------------------------------------------------*/
/*----------------------------------------------------*/
/*----------------------------------------------------*/

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
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
    int n = 5;
    int prev2 = 0;
    int prev = 1;
    for(int i = 2; i<= n; i++) {
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    cout << prev << nl;
    return 0;
}
*/