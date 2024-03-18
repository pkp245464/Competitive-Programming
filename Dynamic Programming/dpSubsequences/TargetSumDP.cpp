//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int cntPartition(int ind,int target,vector<int>&nums) {
	if(ind == 0) {
		if(target == 0 && nums[0] == 0) {
			return 2;
		}
		if(target == 0 || target == nums[0]) {
			return 1;
		}
		return 0;
	}
	int notTaken = cntPartition(ind - 1,target,nums);
	int taken = 0;
	if(nums[ind] <= target) {
		taken = cntPartition(ind - 1,target - nums[ind],nums);
	}
	return notTaken + taken;
}
int findTargetSumWays(vector<int>&nums, int target) {
	int totalSum = accumulate(nums.begin(),nums.end(),0);
	if(totalSum - target < 0 || (totalSum - target) % 2 == 1) {
		return 0;
	}
	int s = (totalSum - target) / 2;
	return cntPartition(nums.size() - 1,s,nums);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    cout << findTargetSumWays(nums,target) << nl;
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
int cntPartition(int ind,int target,vector<int>&nums,vector<vector<int>>&dp) {
	if(ind == 0) {
		if(target == 0 && nums[0] == 0) {
			return 2;
		}
		if(target == 0 || target == nums[0]) {
			return 1;
		}
		return 0;
	}
	if(dp[ind][target] != - 1) {
		return dp[ind][target];
	}
	int notTaken = cntPartition(ind - 1,target,nums,dp);
	int taken = 0;
	if(nums[ind] <= target) {
		taken = cntPartition(ind - 1,target - nums[ind],nums,dp);
	}
	return dp[ind][target] = notTaken + taken;
}
int findTargetSumWays(vector<int>& nums, int target) {
	int totalSum = accumulate(nums.begin(),nums.end(),0);
	if(totalSum - target < 0 || (totalSum - target) % 2 == 1) {
		return 0;
	}
	int s = (totalSum - target) / 2;
	vector<vector<int>>dp(nums.size(),vector<int>(s + 1,-1));
	return cntPartition(nums.size() - 1,s,nums,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    cout << findTargetSumWays(nums,target) << nl;
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
int mod = (int)1e9 + 7;
int findTargetSumWays(vector<int>& nums, int target) {
	int totalSum = accumulate(nums.begin(),nums.end(),0);
	
	if(totalSum - target < 0 || (totalSum - target) % 2) {
		return 0;
	}
	
	int s = (totalSum - target) / 2;
	int n = nums.size();
	
	vector<vector<int>>dp(n,vector<int>(s + 1,0));
	
	if(nums[0] == 0) {
		dp[0][0] = 2;
	}
	else {
		dp[0][0] = 1;
	}
	if(nums[0] != 0 && nums[0] <= s) {
		dp[0][nums[0]] = 1;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= s; j++) {
			int notTaken = dp[i - 1][j];
			int taken = 0;
			if(nums[i] <= j) {
				taken = dp[i - 1][j - nums[i]];
			}
			dp[i][j] = (notTaken + taken) % mod;
		}
	}
	return dp[n -1][s];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    cout << findTargetSumWays(nums,target) << nl;
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
int mod = (int)1e9 + 7;
int findTargetSumWays(vector<int>& nums, int target) {
	int totalSum = accumulate(nums.begin(),nums.end(),0);
	
	if(totalSum - target < 0 || (totalSum - target) % 2) {
		return 0;
	}
	
	int s = (totalSum - target) / 2;
	int n = nums.size();
	
	vector<int>prev(s + 1,0);
	
	if(nums[0] == 0) {
		prev[0] = 2;
	}
	else {
		prev[0] = 1;
	}
	if(nums[0] != 0 && nums[0] <= s) {
		prev[nums[0]] = 1;
	}
	for(int i = 1; i < n; i++) {
		vector<int>cur(s + 1,0);
		for(int j = 0; j <= s; j++) {
			int notTaken = prev[j];
			int taken = 0;
			if(nums[i] <= j) {
				taken = prev[j - nums[i]];
			}
			cur[j] = (notTaken + taken) % mod;
		}
		prev = cur;
	}
	return prev[s];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    cout << findTargetSumWays(nums,target) << nl;
    return 0;
}
*/
