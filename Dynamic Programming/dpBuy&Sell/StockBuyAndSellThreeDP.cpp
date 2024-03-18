//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int buy,int cap,vector<int>&prices) {
	if(ind == prices.size() || cap == 0) {
		return 0;
	}
	if(buy == 1) {
		return max(- prices[ind] + fun(ind + 1,0,cap,prices),0 + fun(ind + 1,1,cap,prices));
	}
	return max(prices[ind] + fun(ind + 1,1,cap - 1,prices),0 + fun(ind + 1,0,cap,prices));
}
int maxProfit(vector<int>& prices) {
	return fun(0,1,2,prices);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {3,3,5,0,0,3,1,4};
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
int fun(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp) {
	if(ind == prices.size() || cap == 0) {
		return 0;
	}
	if(dp[ind][buy][cap] != -1) {
		return dp[ind][buy][cap];
	}
	if(buy == 1) {
		return dp[ind][buy][cap] = max(- prices[ind] + fun(ind + 1,0,cap,prices,dp),0 + fun(ind + 1,1,cap,prices,dp));
	}
	return dp[ind][buy][cap] = max(prices[ind] + fun(ind + 1,1,cap - 1,prices,dp),0 + fun(ind + 1,0,cap,prices,dp));
}
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
	return fun(0,1,2,prices,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {3,3,5,0,0,3,1,4};
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
	vector<vector<vector<int>>>dp(n + 1,vector<vector<int>>(2,vector<int>(3,0)));
	
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int buy = 0; buy <= 1; buy++) {
			for(int cap = 1; cap <= 2; cap++) {
				if(buy == 1) {
					dp[ind][buy][cap] = max(- prices[ind] + dp[ind + 1][0][cap],0 + dp[ind + 1][1][cap]);
				}
				else {
					dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],0 + dp[ind + 1][0][cap]);
				}
			}	
		}
	}
	return dp[0][1][2];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {3,3,5,0,0,3,1,4};
	cout << maxProfit(arr) << nl;
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
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>>prev(2,vector<int>(3,0));
	vector<vector<int>>cur(2,vector<int>(3,0));
	
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int buy = 0; buy <= 1; buy++) {
			for(int cap = 1; cap <= 2; cap++) {
				if(buy == 1) {
					cur[buy][cap] = max(- prices[ind] + prev[0][cap],0 + prev[1][cap]);
				}
				else {
					cur[buy][cap] = max(prices[ind] + prev[1][cap - 1],0 + prev[0][cap]);
				}
			}	
		}
		prev = cur;
	}
	return prev[1][2];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {3,3,5,0,0,3,1,4};
	cout << maxProfit(arr) << nl;
    return 0;
}
*/