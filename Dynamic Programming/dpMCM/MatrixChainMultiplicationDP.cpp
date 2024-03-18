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
	if(i == j) {
		return 0;
	}
	int mini = INT_MAX;
	for(int k = i; k < j; k++) {
		// fun(i to k) and (k + 1 to j) 
		int temp = fun(i,k,arr) + fun(k + 1,j,arr) + arr[i - 1] * arr[j] * arr[k];
		mini = min(mini,temp);
	}
	return mini;
}
int matrixMultiplication(vector<int>&arr) {
	return fun(1,arr.size() - 1,arr);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {40,20,30,10,30};
    cout << matrixMultiplication(arr) << nl;                    
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
int fun(int i,int j,vector<int>&arr,vector<vector<int>>&dp) {
	if(i == j) {
		return 0;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	int mini = INT_MAX;
	for(int k = i; k < j; k++) {
		// fun(i to k) and fun(k + 1,j)
		int temp = fun(i,k,arr,dp) + fun(k + 1,j,arr,dp) + arr[i - 1] * arr[j] * arr[k];
		mini = min(mini,temp);
	}
	return dp[i][j] = mini;
}
int matrixMultiplication(vector<int>&arr) {
	int n = arr.size();
	vector<vector<int>>dp(n + 1,vector<int>(n + 1,-1));
	return fun(1,n - 1,arr,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {40,20,30,10,30};
    cout << matrixMultiplication(arr) << nl;                    
    return 0;
}
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
int matrixMultiplication(vector<int>&arr) {
	int n = arr.size();
	vector<vector<int>>dp(n + 1,vector<int>(n + 1,0));
	for(int i = n - 1; i >= 1; i--) {
		for(int j = i + 1; j < n; j++) {
			int mini = INT_MAX;
			for(int k = i; k < j; k++) {
				int temp = arr[i - 1] * arr[j] * arr[k] + dp[i][k] + dp[k + 1][j];
				mini = min(mini,temp); 
			}
			dp[i][j] = mini;
		}
	}
	return dp[1][n - 1];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {40,20,30,10,30};
    cout << matrixMultiplication(arr) << nl;                    
    return 0;
}
*/