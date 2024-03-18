//Used the function of SubsetSum Equal To Target DP
//Recursion Method
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
bool fun(int ind,int target,vector<int>&nums) {
	if(target == 0) {
		return true;
	}
	if(ind == 0) {
		return nums[ind] == target;
	}
	bool notTake = fun(ind - 1,target,nums);
	bool taken = false;
	if(nums[ind] <= target) {
		taken = fun(ind - 1,target - nums[ind],nums);
	}
	return notTake || taken;
} 
bool canPartition(vector<int>& nums) {
	int sum = accumulate(nums.begin(),nums.end(),0);
	if(sum % 2 != 0) return false;
	int target = sum / 2;
	return fun(nums.size() - 1,target,nums);   
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,2,3,5};
    cout << canPartition(nums) << nl;
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
bool fun(int ind,int target,vector<int>&nums,vector<vector<int>>&dp) {
	if(target == 0) {
		return true;
	}
	if(ind == 0) {
		return nums[ind] == target;
	}
	if(dp[ind][target] != -1) {
		return dp[ind][target];
	}
	bool notTake = fun(ind - 1,target,nums,dp);
	bool taken = false;
	if(nums[ind] <= target) {
		taken = fun(ind - 1,target - nums[ind],nums,dp);
	}
	return dp[ind][target] = notTake || taken;
}
bool canPartition(vector<int>& nums) {
	int sum = accumulate(nums.begin(),nums.end(),0);
	if(sum % 2 != 0) return false;

	int n = nums.size();
	int target = sum / 2;
	vector<vector<int>>dp(n,vector<int>(target + 1,-1));
	return fun(n - 1,target,nums,dp);   
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,2,3,5};
    cout << canPartition(nums) << nl;
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
bool canPartition(vector<int>& nums) {
	int sum = accumulate(nums.begin(),nums.end(),0);
	if(sum % 2 != 0) return false;
	int n = nums.size();
	int k = sum / 2;
	
	vector<vector<bool>>dp(n,vector<bool>(k + 1,false));
	for(int i = 0; i < n; i++) {
		dp[i][0] = true;
	}
	if(nums[0] <= k) {
		dp[0][nums[0]] = true;
	}
	for(int ind = 1; ind < n; ind++) {
		for(int target = 1; target <= k; target++) {
			bool notTake = dp[ind - 1][target];
			bool taken = false;
			if(nums[ind] <= target) {
				taken = dp[ind - 1][target - nums[ind]];
			}
			dp[ind][target] = notTake || taken;
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
    vector<int>nums = {1,2,3,5};
    cout << canPartition(nums) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space optimization

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
bool canPartition(vector<int>& nums) {
	int sum = accumulate(nums.begin(),nums.end(),0);
	if(sum % 2 != 0) return false;
	int n = nums.size();
	int k = sum / 2;
	vector<bool>prev(k + 1,false);
	prev[0] = true;
	
	if(nums[0] <= k) {
		prev[nums[0]] = true;
	}
	for(int ind = 1; ind < n; ind++) {
		vector<bool>cur(k + 1,false);
		cur[0] = true;
		for(int target = 1; target <= k; target++) {
			bool notTake = prev[target];
			bool taken = false;
			if(nums[ind] <= target) {
				taken = prev[target - nums[ind]];
			}
			cur[target] = notTake || taken;
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
    vector<int>nums = {1,2,3,5};
    cout << canPartition(nums) << nl;
    return 0;
}
*/