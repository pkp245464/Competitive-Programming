//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int i,int j,vector<int>&nums) {
	if(i > j) {
		return 0;
	}
	int maxi = INT_MIN;
	for(int ind = i; ind <= j; ind++) {
		int cost = nums[i - 1] * nums[ind] * nums[j + 1] + fun(i,ind - 1,nums) + fun(ind + 1,j,nums);
		maxi = max(maxi,cost);
	}
	return maxi;
}
int maxCoins(vector<int>& nums) {
	int n = nums.size();
	nums.push_back(1);
	nums.insert(nums.begin(),1);
	return fun(1,n,nums);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {3,1,5,8};
    cout << maxCoins(nums) << nl;
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
int fun(int i,int j,vector<int>&nums,vector<vector<int>>&dp) {
	if(i > j) {
		return 0;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	int maxi = INT_MIN;
	for(int ind = i; ind <= j; ind++) {
		int cost = nums[i - 1] * nums[ind] * nums[j + 1] + fun(i,ind - 1,nums,dp) + fun(ind + 1,j,nums,dp);
		maxi = max(maxi,cost);
	}
	return dp[i][j] = maxi;
}
int maxCoins(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>>dp(n + 1,vector<int>(n + 1,-1));
	nums.push_back(1);
	nums.insert(nums.begin(),1);
	return fun(1,n,nums,dp);
}
int main(){
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {3,1,5,8};
    cout << maxCoins(nums) << nl;
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
int maxCoins(vector<int>&nums) {
	int n = nums.size();
	nums.push_back(1);
	nums.insert(nums.begin(),1);
	vector<vector<int>>dp(n + 2,vector<int>(n + 2,0));
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= n; j++) {
			if(i > j) {
				continue;
			}
			int maxi = INT_MIN;
			for(int ind = i; ind <= j; ind++) {
				int cost = nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
				maxi = max(maxi,cost);
			}
			dp[i][j] = maxi;
		}
	}
	return dp[1][n];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {3,1,5,8};
    cout << maxCoins(nums) << nl;
    return 0;
}
*/