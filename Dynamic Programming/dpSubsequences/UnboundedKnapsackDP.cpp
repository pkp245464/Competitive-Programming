// Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int bagSize,vector<int>&profit,vector<int>&weight) {
	if(ind == 0) {
		return ((int)(bagSize / weight[0])) * profit[0];
	}
	int notTaken = 0 + fun(ind - 1,bagSize,profit,weight);
	int taken = INT_MIN;
	if(weight[ind] <= bagSize) {
		taken = profit[ind] + fun(ind,bagSize - weight[ind],profit,weight);
	}
	return max(taken,notTaken);
}
int unboundedKnapsack(int bagSize,vector<int>&profit,vector<int>&weight) {
	return fun(profit.size() - 1,bagSize,profit,weight);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	int bagSize = 10;
	vector<int>profit = {5,11,13};
	vector<int>weight = {2,4,6};
	cout << unboundedKnapsack(bagSize,profit,weight) << nl;
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
int fun(int ind,int bagSize,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp) {
	if(ind == 0) {
		return ((int)(bagSize / weight[0])) * profit[0];
	}
	if(dp[ind][bagSize] != -1) {
		return dp[ind][bagSize];
	}
	int notTaken = 0 + fun(ind - 1,bagSize,profit,weight,dp);
	int taken = INT_MIN;
	if(weight[ind] <= bagSize) {
		taken = profit[ind] + fun(ind,bagSize - weight[ind],profit,weight,dp);
	}
	return dp[ind][bagSize] = max(taken,notTaken);
}
int unboundedKnapsack(int bagSize,vector<int>&profit,vector<int>&weight) {
	vector<vector<int>>dp(profit.size(),vector<int>(bagSize + 1,-1));
	return fun(profit.size() - 1,bagSize,profit,weight,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	int bagSize = 10;
	vector<int>profit = {5,11,13};
	vector<int>weight = {2,4,6};
	cout << unboundedKnapsack(bagSize,profit,weight) << nl;
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
int unboundedKnapsack(int bagSize,vector<int>&profit,vector<int>&weight) {
	int n = profit.size();
	vector<vector<int>>dp(n,vector<int>(bagSize + 1,0));
	for(int i = weight[0]; i <= bagSize; i++) {
		dp[0][i] = ((int)i / weight[0]) * profit[0];
	}
	for(int ind = 1; ind < n; ind++) {
		for(int cap = 0; cap <= bagSize; cap++) {
			int notTaken = 0 + dp[ind - 1][cap];
			int taken = INT_MIN;
			if(weight[ind] <= cap) {
				taken = profit[ind] + dp[ind][cap - weight[ind]];
			}
			dp[ind][cap] = max(taken,notTaken);
		}
	}
	return dp[n - 1][bagSize];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	int bagSize = 10;
	vector<int>profit = {5,11,13};
	vector<int>weight = {2,4,6};
	cout << unboundedKnapsack(bagSize,profit,weight) << nl;
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
int unboundedKnapsack(int bagSize,vector<int>&profit,vector<int>&weight) {
	vector<int>cur(bagSize + 1,0);
	for(int i = weight[0]; i <= bagSize; i++) {
		cur[i] = ((int)i / weight[0]) * profit[0];
	}
	for(int ind = 1; ind < profit.size(); ind++) {
		for(int cap = 0; cap <= bagSize; cap++) {
			int notTaken = 0 + cur[cap];
			int taken = INT_MIN;
			if(weight[ind] <= cap) {
				taken = profit[ind] + cur[cap - weight[ind]];
			}
			cur[cap] = max(taken,notTaken);
		}
	}
	return cur[bagSize];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	int bagSize = 10;
	vector<int>profit = {5,11,13};
	vector<int>weight = {2,4,6};
	cout << unboundedKnapsack(bagSize,profit,weight) << nl;
    return 0;
}
*/