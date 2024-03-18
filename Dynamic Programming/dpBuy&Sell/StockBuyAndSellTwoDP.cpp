//Recursion Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int buy,vector<int>&arr) {
	if(ind == arr.size()) {
		return 0;
	}
	int profit = 0;
	if(buy == 0) {
		profit = max(0 + fun(ind + 1,0,arr),-arr[ind] + fun(ind + 1,1,arr));
	}
	if(buy == 1) {
		profit = max(0 + fun(ind + 1,1,arr),arr[ind] + fun(ind + 1,0,arr));
	}
	return profit;
}
int maxProfit(vector<int>&prices) {
	return fun(0,0,prices);
}       
int main() {          
    fastinput;  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif      
    vector<int>arr = {7,1,5,3,6,4};
    cout << maxProfit(arr) << nl;
    return 0;           
}               

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Memoization Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int buy,vector<int>&arr,vector<vector<int>>&dp) {
	if(ind == arr.size()) {
		return 0;
	}
	if(dp[ind][buy] != -1) {
		return dp[ind][buy];
	}
	int profit = 0;
	if(buy == 0) {
		profit = max(0 + fun(ind + 1,0,arr,dp),-arr[ind] + fun(ind + 1,1,arr,dp));
	}
	if(buy == 1) {
		profit = max(0 + fun(ind + 1,1,arr,dp),arr[ind] + fun(ind + 1,0,arr,dp));
	}
	return dp[ind][buy] = profit;
}
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>>dp(n,vector<int>(2,-1));
	return fun(0,0,prices,dp);
}        
int main() {          
    fastinput;  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif      
    vector<int>arr = {7,1,5,3,6,4};
    cout << maxProfit(arr) << nl;
    return 0;           
}               
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Tabulation Approach

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
	vector<vector<int>>dp(n + 1,vector<int>(2,-1));
	dp[n][0] = dp[n][1] = 0;
	int profit;
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int buy = 0; buy <= 1; buy++) {
			if(buy == 0) {
				profit = max(0 + dp[ind + 1][0],-prices[ind] + dp[ind + 1][1]);
			}
			if(buy == 1) {
				profit = max(0 + dp[ind + 1][1],prices[ind] + dp[ind + 1][0]);
			}
			dp[ind][buy] = profit;
		}
	}
	return dp[0][0];
}        
int main() {          
    fastinput;  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif      
    vector<int>arr = {7,1,5,3,6,4};
    cout << maxProfit(arr) << nl;
    return 0;           
}               
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space Optimization Approach

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
	vector<int>prev(2,0),cur(2,0);
	prev[0] = prev[1] = 0;
	int profit;
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int buy = 0; buy <= 1; buy++) {
			if(buy == 0) {
				profit = max(0 + prev[0],-prices[ind] + prev[1]);
			}
			if(buy == 1) {
				profit = max(0 + prev[1],prices[ind] + prev[0]);
			}
			cur[buy] = profit;
		}
		prev = cur;
	}
	return cur[0];
}   
int main() {          
    fastinput;  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif      
    vector<int>prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << nl;
    return 0;           
}               
*/