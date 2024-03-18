//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int k,vector<int>&nums) {
	int n = nums.size();
	if(ind == n) {
		return 0;
	}
	int len = 0,maxi = INT_MIN,maxAns = INT_MIN;
	for(int i = ind; i < min(ind + k,n); i++) {
		len++;
		maxi = max(maxi,nums[i]);
		int sum = len * maxi + fun(i + 1,k,nums);
		maxAns = max(maxAns,sum);
	}
	return maxAns;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
	return fun(0,k,arr);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << maxSumAfterPartitioning(arr,k) << nl;   
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
int fun(int ind,int k,vector<int>&nums,vector<int>&dp) {
	int n = nums.size();
	if(ind == n) {
		return 0;
	}
	if(dp[ind] != -1) {
		return dp[ind];
	}
	int len = 0,maxi = INT_MIN,maxAns = INT_MIN;
	for(int i = ind; i < min(ind + k,n); i++) {
		len++;
		maxi = max(maxi,nums[i]);
		int sum = len * maxi + fun(i + 1,k,nums,dp);
		maxAns = max(maxAns,sum);
	}
	return dp[ind] = maxAns;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
	int n = arr.size();
	vector<int>dp(n,-1);
	return fun(0,k,arr,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << maxSumAfterPartitioning(arr,k) << nl;   
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
int maxSumAfterPartitioning(vector<int>& arr, int k) {
	int n = arr.size();
	vector<int>dp(n + 1,0);
	for(int ind = n - 1; ind >= 0; ind--) {
		int len = 0,maxi = INT_MIN,maxAns = INT_MIN;
		for(int i = ind; i < min(ind + k,n); i++) {
			len++;
			maxi = max(maxi,arr[i]);
			int sum = len * maxi + dp[i + 1];
			maxAns = max(maxAns,sum);
		}
		dp[ind] = maxAns;
	}
	return dp[0];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << maxSumAfterPartitioning(arr,k) << nl;   
    return 0;
}
*/
