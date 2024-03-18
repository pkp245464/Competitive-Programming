//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int i,int j,vector<int>&arr) {
	if(i > j) {
		return 0;
	}
	int mini = INT_MAX;
	for(int k = i; k <= j; k++) {
		int temp = arr[j + 1] - arr[i - 1] + fun(i,k - 1,arr) + fun(k + 1,j,arr);
		mini = min(mini,temp); 
	}
	return mini;
}
int minCost(int n, vector<int>&arr) {
	int len = arr.size();
	arr.push_back(n);
	arr.insert(arr.begin(),0);
	sort(arr.begin(),arr.end());
	return fun(1,len,arr);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 9;
    vector<int>arr = {5,6,1,4,2};
    cout << minCost(n,arr) << nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Memoization Memoization

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int i,int j,vector<int>&arr,vector<vector<int>>&dp) {
	if(i > j) {
		return 0;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	int mini = INT_MAX;
	for(int k = i; k <= j; k++) {
		int temp = arr[j + 1] - arr[i - 1] + fun(i,k - 1,arr,dp) + fun(k + 1,j,arr,dp);
		mini = min(mini,temp); 
	}
	return dp[i][j] = mini;
}
int minCost(int n, vector<int>&arr) {
	int len = arr.size();
	arr.push_back(n);
	arr.insert(arr.begin(),0);
	sort(arr.begin(),arr.end());
	vector<vector<int>>dp(len + 1,vector<int>(len + 1,-1));
	return fun(1,len,arr,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 9;
    vector<int>arr = {5,6,1,4,2};
    cout << minCost(n,arr) << nl;
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
int minCost(int n, vector<int>&arr) {
	int len = arr.size();
	arr.push_back(n);
	arr.insert(arr.begin(),0);
	sort(arr.begin(),arr.end());
	vector<vector<int>>dp(len + 2,vector<int>(len + 2,0));
	for(int i = len; i >= 1; i--) {
		for(int j = 1; j <= len; j++) {
			if(i > j) {
				continue;
			}
			int mini = INT_MAX;
			for(int k = i; k <= j; k++) {
				int temp = arr[j + 1] - arr[i - 1] + dp[i][k - 1] + dp[k + 1][j];
				mini = min(mini,temp); 
			}
			dp[i][j] = mini;
		}
	}
	return dp[1][len];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 9;
    vector<int>arr = {5,6,1,4,2};
    cout << minCost(n,arr) << nl;
    return 0;
}
*/