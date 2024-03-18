//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int buy,vector<int>&prices) {
	if(ind >= prices.size()) {
		return 0;
	}
	if(buy == 1) {
		return max(- prices[ind] + fun(ind + 1,0,prices),0 + fun(ind + 1,1,prices));
	}
	return max(prices[ind] + fun(ind + 2,1,prices),0 + fun(ind + 1,0,prices));
}
int maxProfit(vector<int>& prices) {
	return fun(0,1,prices);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {1,2,3,0,2};
	cout << maxProfit(arr) << nl;
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
int fun(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp) {
	if(ind >= prices.size()) {
		return 0;
	}
	if(dp[ind][buy] != -1) {
		return dp[ind][buy];
	}
	if(buy == 1) {
		return dp[ind][buy] = max(- prices[ind] + fun(ind + 1,0,prices,dp),0 + fun(ind + 1,1,prices,dp));
	}
	return dp[ind][buy] = max(prices[ind] + fun(ind + 2,1,prices,dp),0 + fun(ind + 1,0,prices,dp));
}
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>>dp(n,vector<int>(2,-1));
	return fun(0,1,prices,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {1,2,3,0,2};
	cout << maxProfit(arr) << nl;
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
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>>dp(n + 2,vector<int>(2,0));
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int buy = 0; buy <= 1; buy++) {
			if(buy == 1) {
				dp[ind][buy] = max(- prices[ind] + dp[ind + 1][0],0 + dp[ind + 1][1]);
			}
			else {
				dp[ind][buy] = max(prices[ind] + dp[ind + 2][1],0 + dp[ind + 1][0]);
			}
		}
	}
	return dp[0][1];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {1,2,3,0,2};
	cout << maxProfit(arr) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Space Optimization method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<int>cur(2,0),front1(2,0),front2(2,0);
	for(int ind = n - 1; ind >= 0; ind--) {
		int profit;
		for(int buy = 0; buy <= 1; buy++) {
			if(buy == 0) {
				profit = max(-prices[ind] + front1[1],front1[0]);
			}
			else {
				profit = max(prices[ind] + front2[0],front1[1]);
			}
			cur[buy] = profit;
		}
		front2 = front1;
		front1 = cur;
	}
	return cur[0];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {1,2,3,0,2};
    cout << maxProfit(arr) << nl;             
    return 0;
}
*/