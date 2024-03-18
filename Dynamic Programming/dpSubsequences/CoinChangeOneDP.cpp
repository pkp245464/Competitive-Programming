//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int amount,vector<int>&nums) {
	if(ind == 0) {
		if(amount % nums[0] == 0) {
			return amount / nums[0];
		}
		else {
			return 1e9;
		}
	}
	int notTaken = 0 + fun(ind - 1,amount,nums);
	int taken = 1e9;
	if(nums[ind] <= amount) {
		taken = 1 + fun(ind,amount - nums[ind],nums);
	}            
	return min(taken,notTaken);
}
int coinChange(vector<int>& coins, int amount) {
	int ans = fun(coins.size() - 1,amount,coins);
	if(ans >= 1e9) {
		return -1;
	}
	return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>coins = {1,2,3};
    int amount = 7;
    cout << coinChange(coins,amount) << nl;    
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
int fun(int ind,int amount,vector<int>&nums,vector<vector<int>>&dp) {
	if(ind == 0) {
		if(amount % nums[0] == 0) {
			return amount / nums[0];
		}
		else {
			return 1e9;
		}
	}
	if(dp[ind][amount] != -1) {
		return dp[ind][amount];
	}
	int notTaken = 0 + fun(ind - 1,amount,nums,dp);
	int taken = 1e9;
	if(nums[ind] <= amount) {
		taken = 1 + fun(ind,amount - nums[ind],nums,dp);
	}            
	return  dp[ind][amount] = min(taken,notTaken);
}
int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	vector<vector<int>>dp(n,vector<int>(amount + 1,-1));
	int ans = fun(coins.size() - 1,amount,coins,dp);
	if(ans >= 1e9) {
		return -1;
	}
	return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>coins = {1,2,3};
    int amount = 7;
    cout << coinChange(coins,amount) << nl;    
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
int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	vector<vector<int>>dp(n,vector<int>(amount + 1,0));
	
	for(int i = 0; i <= amount; i++) {
		if(i % coins[0] == 0) {
			dp[0][i] = i / coins[0];
		}
		else {
			dp[0][i] = 1e9;
		}
	}
	for(int ind = 1; ind < n; ind++) {
		for(int target = 0; target <= amount; target++) {
			int notTaken = 0 + dp[ind - 1][target];
			int taken = 1e9;
			if(coins[ind] <= target) {
				taken = 1 + dp[ind][target - coins[ind]];
			}
			dp[ind][target] = min(taken,notTaken);
		}
	}
	int ans = dp[n - 1][amount];
	if(ans >= 1e9) {
		return -1;
	}
	return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>coins = {1,2,3};
    int amount = 7;
    cout << coinChange(coins,amount) << nl;    
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
int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	
	vector<int>prev(amount + 1,0),cur(amount + 1,0);
			
	for(int i = 0; i <= amount; i++) {
		if(i % coins[0] == 0) {
			prev[i] = i / coins[0];
		}
		else {
			prev[i] = 1e9;
		}
	}
	for(int ind = 1; ind < n; ind++) {
		for(int target = 0; target <= amount; target++) {
			int notTaken = 0 + prev[target];
			int taken = 1e9;
			if(coins[ind] <= target) {
				taken = 1 + cur[target - coins[ind]];
			}
			cur[target] = min(taken,notTaken);
		}
		prev = cur;
	}
	int ans = prev[amount];
	if(ans >= 1e9) {
		return -1;
	}
	return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>coins = {1,2,3};
    int amount = 7;
    cout << coinChange(coins,amount) << nl;    
    return 0;
}
*/