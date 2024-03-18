//We can Solve Using Buy And Sell III problem
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>>prev(2,vector<int>(k + 1,0));
	vector<vector<int>>cur(2,vector<int>(k + 1,0));
	
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int buy = 0; buy <= 1; buy++) {
			for(int cap = 1; cap <= k; cap++) {
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
	return prev[1][k];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {2,4,1};
	int k = 2;
	cout << maxProfit(k,arr) << nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

//Another Way to solve

/*
//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int tranNo,int k,vector<int>&prices) {
	if(ind == prices.size() || tranNo == 2 * k) {
		return 0;
	}
	if(tranNo % 2 == 0) {
		return max(- prices[ind] + fun(ind + 1,tranNo + 1,k,prices),0 + fun(ind + 1,tranNo,k,prices));
	}
	return max(prices[ind] + fun(ind + 1,tranNo + 1,k,prices),0 + fun(ind + 1,tranNo,k,prices));
}
int maxProfit(int k, vector<int>& prices) {
	return fun(0,0,k,prices);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {2,4,1};
	int k = 2;
	cout << maxProfit(k,arr) << nl;
    return 0;
}
*/

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
int fun(int ind,int tranNo,int k,vector<int>&prices,vector<vector<int>>&dp) {
	if(ind == prices.size() || tranNo == 2 * k) {
		return 0;
	}
	if(dp[ind][tranNo] != -1) {
		return dp[ind][tranNo];
	}
	if(tranNo % 2 == 0) {
		return dp[ind][tranNo] = max(- prices[ind] + fun(ind + 1,tranNo + 1,k,prices,dp),0 + fun(ind + 1,tranNo,k,prices,dp));
	}
	return dp[ind][tranNo] = max(prices[ind] + fun(ind + 1,tranNo + 1,k,prices,dp),0 + fun(ind + 1,tranNo,k,prices,dp));
}
int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>>dp(n,vector<int>(2 * k,-1));
	return fun(0,0,k,prices,dp);
}

int main(){
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {2,4,1};
	int k = 2;
	cout << maxProfit(k,arr) << nl;
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
int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>>dp(n + 1,vector<int>(2 * k + 1,0));
	
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int tranNo = 2 * k - 1; tranNo >= 0; tranNo--) {
			if(tranNo % 2 == 0) {
				dp[ind][tranNo] = max(- prices[ind] + dp[ind + 1][tranNo + 1],0 + dp[ind + 1][tranNo]);
			}
			else {
				dp[ind][tranNo] = max(prices[ind] + dp[ind + 1][tranNo + 1],0 + dp[ind + 1][tranNo]);	
			}
		}
	}
	return dp[0][0];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {2,4,1};
	int k = 2;
	cout << maxProfit(k,arr) << nl;
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
int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	vector<int>prev(2 * k + 1,0);
	vector<int>cur(2 * k + 1,0);
	
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int tranNo = 2 * k - 1; tranNo >= 0; tranNo--) {
			if(tranNo % 2 == 0) {
				cur[tranNo] = max(- prices[ind] + prev[tranNo + 1],0 + prev[tranNo]);
			}
			else {
				cur[tranNo] = max(prices[ind] + prev[tranNo + 1],0 + prev[tranNo]);	
			}
		}
		prev = cur;
	}
	return prev[0];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	vector<int>arr = {2,4,1};
	int k = 2;
	cout << maxProfit(k,arr) << nl;
    return 0;
}
*/