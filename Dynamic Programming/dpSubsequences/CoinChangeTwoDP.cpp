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
		return (amount % nums[0] == 0);
	}
	int notTaken = fun(ind - 1,amount,nums);
	int taken = 0;
	if(nums[ind] <= amount) {
		taken = fun(ind,amount - nums[ind],nums);
	}
	return taken + notTaken;
}
int change(int amount, vector<int>&coins) {
	return fun(coins.size() - 1,amount,coins);    
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int amount = 5;
    vector<int>arr = {1,2,5};
    cout << change(amount,arr) << nl;
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
		return (amount % nums[0] == 0);
	}
	if(dp[ind][amount] != -1) {
		return dp[ind][amount];
	}
	int notTaken = fun(ind - 1,amount,nums,dp);
	int taken = 0;
	if(nums[ind] <= amount) {
		taken = fun(ind,amount - nums[ind],nums,dp);
	}
	return dp[ind][amount] = taken + notTaken;
}
int change(int amount, vector<int>&coins) {
	vector<vector<int>>dp(coins.size(),vector<int>(amount + 1,-1));
	return fun(coins.size() - 1,amount,coins,dp);    
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int amount = 5;
    vector<int>arr = {1,2,5};
    cout << change(amount,arr) << nl;
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
int change(int amount, vector<int>&coins) {
	int n = coins.size();
	vector<vector<int>>dp(n,vector<int>(amount + 1,0));
	for(int i = 0; i <= amount; i++) {
		if(i % coins[0] == 0) {
			dp[0][i] = 1;
		}
	}
	for(int ind = 1; ind < n; ind++) {
		for(int tar = 0; tar <= amount; tar++) {
			int notTaken = dp[ind - 1][tar];
			int taken = 0;
			if(coins[ind] <= tar) {
				taken = dp[ind][tar - coins[ind]];
			}
			dp[ind][tar] = taken + notTaken;
		}
	}
	return dp[n - 1][amount];  
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int amount = 5;
    vector<int>arr = {1,2,5};
    cout << change(amount,arr) << nl;
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
int change(int amount, vector<int>&coins) {
	int n = coins.size();
	vector<int>prev(amount + 1,0);

	for(int i = 0; i <= amount; i++) {
		if(i % coins[0] == 0) {
			prev[i] = 1;
		}
	}
	for(int ind = 1; ind < n; ind++) {
		vector<int>cur(amount + 1,0);
		for(int tar = 0; tar <= amount; tar++) {
			int notTaken = prev[tar];
			int taken = 0;
			if(coins[ind] <= tar) {
				taken = cur[tar - coins[ind]];
			}
			cur[tar] = taken + notTaken;
		}
		prev = cur;
	}
	return prev[amount];  
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int amount = 5;
    vector<int>arr = {1,2,5};
    cout << change(amount,arr) << nl;
    return 0;
}
*/