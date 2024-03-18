//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int k,vector<int>&arr) {
    if(ind == 0) {
        return 0;
    }
    int minimumStep = INT_MAX;
    for(int i = 1; i <= k; i++) {
        if(ind - i >= 0) {
            int jump = fun(ind - i,k,arr) + abs(arr[ind] - arr[ind - i]);
            minimumStep = min(minimumStep,jump);
        }
    }
    return minimumStep;
}
int minimumCost(int k,vector<int>&arr) {
    int n = arr.size();
    return fun(n - 1,k,arr);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << minimumCost(k,arr) << nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Memoization Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int k,vector<int>&arr,vector<int>&dp) {
    if(ind == 0) {
        return 0;
    }
    if(dp[ind] != -1) {
        return dp[ind];
    }
    int minimumStep = INT_MAX;
    for(int i = 1; i <= k; i++) {
        if(ind - i >= 0) {
            int jump = fun(ind - i,k,arr,dp) + abs(arr[ind] - arr[ind - i]);
            minimumStep = min(minimumStep,jump);
        }
    }
    return dp[ind] = minimumStep;
}
int minimumCost(int k,vector<int>&arr) {
    int n = arr.size();
    vector<int>dp(n,-1);
    return fun(n - 1,k,arr,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << minimumCost(k,arr) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Tabulation Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
    fastinput;
#ifndef ONLINE_JUDGEz
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int>dp(n,0);
    dp[0] = 0;
    for(int i = 1; i < n; i++) {  
        int minStep = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                minStep = min(jump,minStep);
            }
        }
        dp[i] = minStep;
    }
    cout << dp[n - 1] << nl;
    return 0;
}
*/

