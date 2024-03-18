//Using Recursion Solution

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int frogJump(int ind,vector<int>&nums) {
	if(ind == 0) {
		return 0;
	} 
	int jumpOne,jumpTwo;
	jumpOne = frogJump(ind - 1,nums) + abs(nums[ind] - nums[ind - 1]);
	if(ind > 1) {
		jumpTwo = frogJump(ind - 2,nums) + abs(nums[ind] - nums[ind - 2]);
	}
	return min(jumpOne,jumpTwo);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr{10,20,30,10};
    int n = arr.size();
    cout << frogJump(n-1,arr) << nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Memoization Approach Solution

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int frogJump(int ind,vector<int>&nums,vector<int>&dp) {
	if(ind == 0) {
		return 0;
	}
	if(dp[ind] != -1) {
		return dp[ind];
	}
	int jumpOne,jumpTwo = INT_MAX;
	jumpOne = frogJump(ind - 1,nums,dp) + abs(nums[ind] - nums[ind - 1]);
	if(ind > 1) {
		jumpTwo = frogJump(ind - 2,nums,dp) + abs(nums[ind] - nums[ind - 2]);
	}
	return dp[ind] = min(jumpOne,jumpTwo);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr{10,20,30,10};
    int n = arr.size();
    vector<int>dp(n,-1);
    cout << frogJump(n - 1,arr,dp) << nl;
    return 0;
}
*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Tabulation Approach Solution

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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr{30,10,60,10,60,50};
    int n = arr.size();
    vector<int>dp(n,-1);
    dp[0] = 0;
    for(int ind = 1; ind < n; ind++) {
        int jumpOne = dp[ind - 1] + abs(arr[ind] - arr[ind - 1]);
            int jumpTwo = INT_MAX;
        if(ind > 1) {
            jumpTwo = dp[ind - 2] + abs(arr[ind] - arr[ind - 2]);
        }
        dp[ind] = min(jumpOne,jumpTwo);
    }
    cout << dp[n-1] << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space Optimization

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
    vector<int>arr{30,10,60,10,60,50};
    int n = arr.size();
    int prev1 = 0,prev2 = 0;
    for(int ind = 1; ind < n; ind++) {
        int jumpOne = prev1 + abs(arr[ind] - arr[ind - 1]);
            int jumpTwo = INT_MAX;
        if(ind > 1) {
            jumpTwo = prev2 + abs(arr[ind] - arr[ind - 2]);
        }
        int cur = min(jumpOne,jumpTwo);
        prev2 = prev1;
        prev1 = cur;
    }
    cout << prev1 << nl;
    return 0;
}
*/
