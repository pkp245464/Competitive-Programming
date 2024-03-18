//Recursion Method
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int n,vector<int>&arr) {
	if(ind == 0) {
		return n * arr[0];
	}
	int notTaken = 0 + fun(ind - 1,n,arr);
	int taken = INT_MIN;
	int rodLen = ind + 1;
	if(rodLen <= n) {
		taken = arr[ind] + fun(ind,n - rodLen,arr);
	}
	return max(taken,notTaken);
}
int rodCutting(vector<int>&price) {
	int n = price.size();
	return fun(n - 1,n,price);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {2,5,7,8,10};
    cout << rodCutting(arr) << nl;
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
int fun(int ind,int n,vector<int>&arr,vector<vector<int>>&dp) {
	if(ind == 0) {
		return n * arr[0];
	}
	if(dp[ind][n] != -1) {
		return dp[ind][n];
	}
	int notTaken = 0 + fun(ind - 1,n,arr,dp);
	int taken = INT_MIN;
	int rodLen = ind + 1;
	if(rodLen <= n) {
		taken = arr[ind] + fun(ind,n - rodLen,arr,dp);
	}
	return dp[ind][n] = max(taken,notTaken);
}
int rodCutting(vector<int>&price) {
	int n = price.size();
	vector<vector<int>>dp(n,vector<int>(n + 1,-1));
	return fun(n - 1,n,price,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {2,5,7,8,10};
    cout << rodCutting(arr) << nl;
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
int rodCutting(vector<int>&price) {
	int n = price.size();
	vector<vector<int>>dp(n,vector<int>(n + 1,0));
	
	for(int i = 0; i <= n; i++) {
		dp[0][i] = i * price[0];
	}
	
	for(int ind = 1; ind < n; ind++) {
		for(int len = 0; len <= n; len++) {
			int notTaken = 0 + dp[ind - 1][len];
			int taken = INT_MIN;
			int rodLen = ind + 1;
			if(rodLen <= len) {
				taken = price[ind] + dp[ind][len - rodLen];
			}
			dp[ind][len] = max(taken,notTaken);
		}
	}
	return dp[n - 1][n];
}

int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {2,5,7,8,10};
    cout << rodCutting(arr) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space Optimization

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int rodCutting(vector<int>&price) {
	int n = price.size();
	vector<int>cur(n + 1,0);
	for(int i = 0; i <= n; i++) {
		cur[i] = i * price[0];
	}
	for(int ind = 1; ind < n; ind++) {
		for(int len = 0; len <= n; len++) {
			int notTaken = 0 + cur[len];
			int taken = INT_MIN;
			int rodLen = ind + 1;
			if(rodLen <= len) {
				taken = price[ind] + cur[len - rodLen];
			}
			cur[len] = max(taken,notTaken);
		}
	}
	return cur[n];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {2,5,7,8,10};
    cout << rodCutting(arr) << nl;
    return 0;
}
*/