//Array contain all postive element
//Memoization Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
bool fun(int ind,int target,vector<int>&arr,vector<vector<long long>>&dp) {
	if(target == 0) {
		return dp[ind][target] = true;
	}
	if(ind == 0) {
		return dp[ind][target] = arr[ind] ==  target;
	}
	if(dp[ind][target] != -1) {
		return dp[ind][target];
	}
	bool notTaken = fun(ind - 1,target,arr,dp);
	bool taken = false;
	if(arr[ind] <= target) {
		taken = fun(ind - 1,target - arr[ind],arr,dp);
	}
	return dp[ind][target] = taken || notTaken;
}
int minimumDifference(vector<int>&arr) {
	int n = arr.size(),totalSum = 0,ans = INT_MAX;
	for(int i = 0; i < n; i++) {
		totalSum += arr[i];
	}
	vector<vector<long long>>dp(n,vector<long long>(totalSum + 1,-1));
	for(int i = 0; i <= totalSum; i++) {
		bool temp = fun(n - 1,i,arr,dp);
	}
	for(int i = 0; i <= totalSum; i++) {
		if(dp[n - 1][i] == true) {
			int dif = abs(i - (totalSum - i));
			ans = min(ans,dif);
		}
	}
	return ans;
}	
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {3,9,7,3};
    cout << minimumDifference(arr) << nl;    
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
int minimumDifference(vector<int>&nums) {
	int n = nums.size();
	int sum = accumulate(nums.begin(),nums.end(),0);
	vector<vector<bool>>dp(n,vector<bool>(sum + 1,false));

	for(int i = 0; i < n; i++) {
		dp[i][0] = true;
	}
	if(nums[0] <= sum) {
		dp[0][sum] = true;
	}
	for(int ind = 1; ind < n; ind++) {
		for(int target = 1; target <= sum; target++) {
			bool notTaken = dp[ind - 1][target];
			bool taken = false;
			if(nums[ind] <= target) {
				taken = dp[ind - 1][target - nums[ind]];
			}
			dp[ind][target] = notTaken || taken;
		}
	}

	int mini = 1e9;
	for(int i = 0; i <= sum; i++) {
		if(dp[n -1][i] == true) {
			int diff = abs(i - (sum - i));
			mini = min(mini,diff);
		}
	}
	return mini;    
}

int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {3,9,7,3};
    cout << minimumDifference(nums) << nl;
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
int minimumDifference(vector<int>& nums) {
	int n = nums.size();
	int sum = accumulate(nums.begin(),nums.end(),0);
	vector<bool>prev(sum + 1,false);
	prev[0] = true;

	if(nums[0] <= sum) {
		prev[nums[0]] = true;
	}

	for(int ind = 1; ind < n; ind++) {
		vector<bool>cur(sum + 1,false);
		cur[0] = true;
		for(int target = 1; target <= sum; target++) {
			bool notTaken = prev[target];
			bool taken = false;
			if(nums[ind] <= target) {
				taken = prev[target - nums[ind]];
			}
			cur[target] = notTaken || taken;
		}
		prev = cur;
	}
	int mini = 1e9;
	for(int i = 0; i <= sum; i++) {
		if(prev[i] == true) {
			int diff = abs(i - (sum - i));
			mini = min(mini,diff);
		}
	}
	return mini;    
}
int main(){ 
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {3,9,7,3};
    cout << minimumDifference(nums) << nl;
    return 0;
}
*/





