// Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int target,vector<int>&nums) {
	if(target == 0) {
		return 1;
	}
	if(ind == 0) {
		return nums[ind] == target;
	}
	int notTaken = fun(ind - 1,target,nums);
	int taken = 0;
	if(nums[ind] <= target) {
		taken = fun(ind - 1,target - nums[ind],nums);
	}
	return notTaken + taken;
}
int cntSubsetWithSumK(vector<int>&nums,int target) {
	int n = nums.size();
	return fun(n - 1,target,nums);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,2,2,3};
    int target = 3;
    cout << cntSubsetWithSumK(nums,target) << nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Memoization Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int target,vector<int>&nums,vector<vector<int>>&dp) {
	if(target == 0) {
		return 1;
	}
	if(ind == 0) {
		return nums[ind] == target;
	}
	if(dp[ind][target] != -1) {
		return dp[ind][target];
	}
	int notTaken = fun(ind - 1,target,nums,dp);
	int taken = 0;
	if(nums[ind] <= target) {
		taken = fun(ind - 1,target - nums[ind],nums,dp);
	}
	return dp[ind][target] = notTaken + taken;
}
int cntSubsetWithSumK(vector<int>& nums, int target) {
	int n = nums.size();
	vector<vector<int>>dp(n,vector<int>(target + 1,-1));
	return fun(n - 1,target,nums,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,2,2,3};
    int target = 3;
    cout << cntSubsetWithSumK(nums,target) << nl;
    return 0;
}
*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Tabulation Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int cntSubsetWithSumK(vector<int>& nums, int k) {
	int n = nums.size();
	vector<vector<int>>dp(n,vector<int>(k + 1,0));
	for(int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}
	if(nums[0] <= k) {
		dp[0][nums[0]] = 1;
	}
	for(int ind = 1; ind < n; ind++) {
		for(int target = 1; target <= k; target++) {
			int notTaken = dp[ind - 1][target];
			int taken = 0;
			if(nums[ind] <= target) {
				taken = dp[ind - 1][target - nums[ind]];
			}
			dp[ind][target] = notTaken + taken;
		}
	}
	return dp[n - 1][k];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,2,2,3};
    int target = 3;
    cout << cntSubsetWithSumK(nums,target) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space Optimization Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int cntSubsetWithSumK(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int>prev(k + 1,0);
	prev[0] = 1;
	if(nums[0] <= k) {
		prev[nums[0]] = 1;
	}
	for(int ind = 1; ind < n; ind++) {
		vector<int>cur(k + 1,0);
		cur[0] = 1;
		for(int target = 1; target <= k; target++) {
			int notTaken = prev[target];
			int taken = 0;
			if(nums[ind] <= target) {
				taken = prev[target - nums[ind]];
			}
			cur[target] = notTaken + taken;
		}
		prev = cur;
	}
	return prev[k];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,2,2,3};
    int target = 3;
    cout << cntSubsetWithSumK(nums,target) << nl;
    return 0;
}
*/







































