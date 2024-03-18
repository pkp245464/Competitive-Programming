//Same Question - Count Subsets with sum k (it failed when array element will be zero 
//we have to modify the base conditions)
//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int MOD = (int)1e9 + 7;
int fun(int ind,int target,vector<int>&nums) {
	if(ind == 0) {
		if(target == 0 && nums[0] == 0) {
			return 2;
		}
		if(target == 0 || target == nums[0]) {
			return 1;
		}
		return 0;
	}
	int notTaken = fun(ind - 1,target,nums);
	int taken = 0;
	if(nums[ind] <= target) {
		taken = fun(ind - 1,target - nums[ind],nums);
	}
	return  (notTaken + taken) % MOD;
}
int findWays(vector<int>&nums,int d) {
	int n = nums.size();
	int totalSum = accumulate(nums.begin(),nums.end(),0);
	if(totalSum -d < 0) {
		return 0;
	}
	if((totalSum - d) % 2 == 1) {
		return 0;
	}
	int s = (totalSum - d) / 2;
	return fun(n - 1,s,nums);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {5,2,6,4};
	int k = 3;
	cout << findWays(arr,k) << nl;
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
int MOD = (int)1e9 + 7;
int fun(int ind,int target,vector<int>&nums,vector<vector<int>>&dp) {
	if(ind == 0) {
		if(target == 0 && nums[0] == 0) {
			return 2;
		}
		if(target == 0 || target == nums[0]) {
			return 1;
		}
		return 0;
	}
	if(dp[ind][target] != -1) {
		return dp[ind][target];
	}
	int notTaken = fun(ind - 1,target,nums,dp);
	int taken = 0;
	if(nums[ind] <= target) {
		taken = fun(ind - 1,target - nums[ind],nums,dp);
	}
	return  dp[ind][target] = (notTaken + taken) % MOD;
}
int findWays(vector<int>&nums,int d) {
	int n = nums.size();
	int totalSum = accumulate(nums.begin(),nums.end(),0);
	if(totalSum -d < 0) {
		return 0;
	}
	if((totalSum - d) % 2 == 1) {
		return 0;
	}
	int s = (totalSum - d) / 2;
	vector<vector<int>>dp(n,vector<int>(s + 1,-1));
	return fun(n - 1,s,nums,dp);
}

int main(){
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {5,2,6,4};
	int k = 3;
	cout << findWays(arr,k) << nl;
 	return 0;
}

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
int MOD = (int)1e9 + 7;
int fun(vector<int>&nums,int k) {
	int n = nums.size();
	vector<vector<int>>dp(n,vector<int>(k + 1,0));
	if(nums[0] == 0) {
		dp[0][0] = 2;
	}
	else {
		dp[0][0] = 1;
	}
	if(nums[0] != 0 && nums[0] <= k) {
		dp[0][nums[0]] = 1;
	}
	for(int ind = 1; ind < n; ind++) {
		for(int tar = 0; tar <= k; tar++) {
			int notTaken = dp[ind - 1][tar];
			int taken = 0;
			if(nums[ind] <= tar) {
				taken = dp[ind - 1][tar - nums[ind]];
			}
			dp[ind][tar] = (notTaken + taken) % MOD; 
		}
	}
	return dp[n - 1][k];
}
int findWays(vector<int>&nums,int d) {
	int n = nums.size();
	int totalSum = accumulate(nums.begin(),nums.end(),0);
	if(totalSum - d < 0 || (totalSum - d) % 2) {
		return 0;
	}
	return fun(nums,(totalSum - d) / 2);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {1,1,1,1};
	int k = 0;
	cout << findWays(arr,k) << nl;
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
int MOD = (int)1e9 + 7;
int fun(vector<int>&nums,int k) {
	int n = nums.size();
	vector<int>prev(k + 1,0);
	if(nums[0] == 0) {
		prev[0] = 2;
	}
	else {
		prev[0] = 1;
	}
	if(nums[0] != 0 && nums[0] <= k) {
		prev[nums[0]] = 1;
	}
	for(int ind = 1; ind < n; ind++) {
		vector<int>cur(k + 1,0);
		for(int tar = 0; tar <= k; tar++) {
			int notTaken = prev[tar];
			int taken = 0;
			if(nums[ind] <= tar) {
				taken = prev[tar - nums[ind]];
			}
			cur[tar] = (notTaken + taken) % MOD; 
		}
		prev = cur;
	}
	return prev[k];
}
int findWays(vector<int>&nums,int d) {
	int n = nums.size();
	int totalSum = accumulate(nums.begin(),nums.end(),0);
	if(totalSum - d < 0 || (totalSum - d) % 2) {
		return 0;
	}
	return fun(nums,(totalSum - d) / 2);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {1,1,1,1};
	int k = 0;
	cout << findWays(arr,k) << nl;
 	return 0;
}
*/