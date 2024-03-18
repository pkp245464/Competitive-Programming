//Same Question Buy And Sell Two , Just Subtract fee otherwise whole code is Same

//Meoization Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int buy,int fee,vector<int>&arr,vector<vector<int>>&dp) {
	if(ind == arr.size()) {
		return 0;
	}
	if(dp[ind][buy] != -1) {
		return dp[ind][buy];
	}
	int profit = 0;
	if(buy == 0) {
		profit = max(0 + fun(ind + 1,0,fee,arr,dp),-arr[ind] -fee + fun(ind + 1,1,fee,arr,dp));
	}
	if(buy == 1) {
		profit = max(0 + fun(ind + 1,1,fee,arr,dp),arr[ind] + fun(ind + 1,0,fee,arr,dp));
	}
	return dp[ind][buy] = profit;
}
int maxProfit(vector<int>& prices, int fee) {
	 int n = prices.size();
	vector<vector<int>>dp(n,vector<int>(2,-1));
	return fun(0,0,fee,prices,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	int fee = 2;
	vector<int>arr = {1,3,2,8,4,9};
	cout << maxProfit(arr,fee) << nl;
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
int maxProfit(vector<int>&arr,int fee) {
    int n = arr.size();
    if(n == 0) {
        return 0; 
    }
    vector<vector<int>>dp(n + 1,vector<int>(2,0));
    for(int ind = n - 1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            int profit;
            if (buy == 0) { 
                profit = max(0 + dp[ind + 1][0],-arr[ind] + dp[ind + 1][1]);
            }
            if (buy == 1) { 
                profit = max(0 + dp[ind + 1][1],arr[ind] - fee + dp[ind + 1][0]);
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
    int fee = 2;
    vector<int>arr = {1,3,2,8,4,9};
    cout << maxProfit(arr,fee) << nl;    
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space optimization

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int maxProfit(vector<int>&arr,int fee) {
    int n = arr.size();
    if(n == 0) {
        return 0; 
    }
    vector<int>ahead(2, 0),cur(2, 0);   
    ahead[0] = ahead[1] = 0;
    int profit;
    for(int ind = n - 1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy == 0) {
                profit = max(0 + ahead[0],-arr[ind] + ahead[1]);
            }
            if (buy == 1) {
                profit = max(0 + ahead[1],arr[ind] - fee + ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }
    return cur[0]; 
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int fee = 2;
    vector<int>arr = {1,3,2,8,4,9};
    cout << maxProfit(arr,fee) << nl;    
    return 0;
}
*/