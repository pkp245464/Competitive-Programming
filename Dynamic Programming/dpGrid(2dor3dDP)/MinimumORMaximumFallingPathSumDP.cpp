//Recursion Method
   
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int i,int j,vector<vector<int>>&matrix) {
	if(j < 0 || j >= matrix[0].size()) {
		return -1e9;
	}
	if(i == 0) {
		return matrix[0][j];
	}
	int up = matrix[i][j] + fun(i - 1,j,matrix); 
	int leftDiagonal = matrix[i][j] + fun(i - 1,j - 1,matrix);
	int rightDiagonal = matrix[i][j] + fun(i - 1,j + 1,matrix);
	return max({up,leftDiagonal,rightDiagonal});
}
int getMaxPathSum(vector<vector<int>> &matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int ans = INT_MIN;
	for(int j = 0; j < n; j++) {
		int val = fun(m - 1,j,matrix);
		ans = max(ans,val);
	}
	return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>arr = {{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    cout << getMaxPathSum(arr) << nl;                 
    return 0;
}

/*-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------*/

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
int fun(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp) {
	if(j < 0 || j >= matrix[0].size()) {
		return -1e9;
	}
	if(i == 0) {
		return matrix[0][j];
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	int up = matrix[i][j] + fun(i - 1,j,matrix,dp); 
	int leftDiagonal = matrix[i][j] + fun(i - 1,j - 1,matrix,dp);
	int rightDiagonal = matrix[i][j] + fun(i - 1,j + 1,matrix,dp);
	return dp[i][j] = max({up,leftDiagonal,rightDiagonal});
}
int getMaxPathSum(vector<vector<int>> &matrix) {
	int ans = INT_MIN;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>>dp(m,vector<int>(n,-1));
	for(int j = 0; j < n; j++) {
		int val = fun(m - 1,j,matrix,dp);
		ans = max(ans,val);
	}
	return ans;
}

int main() {
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p = new Solution();
    vector<vector<int>>arr = {{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    cout << p->getMaxPathSum(arr) << nl;                 
    return 0;
}
*/

/*-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------*/

/*
//Tabulation Method

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int getMaxPathSum(vector<vector<int>> &matrix) {
	int ans = INT_MIN;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>>dp(m,vector<int>(n,0));
	for(int j = 0; j < n; j++) {
		dp[0][j] = matrix[0][j];
	}
	for(int i = 1; i < m; i++) {
		for(int j = 0; j < n; j++) {
			int up = matrix[i][j] + dp[i - 1][j]; 
			int leftDiagonal = matrix[i][j];
			if(j - 1 >= 0) {
				leftDiagonal += dp[i - 1][j - 1];
			}
			else {
				leftDiagonal += (-1e9);
			}
			int rightDiagonal = matrix[i][j];
			if(j + 1 < n) {
				rightDiagonal += dp[i - 1][j + 1];
			}
			else {
				rightDiagonal += (-1e9);
			}
			dp[i][j] = max({up,leftDiagonal,rightDiagonal});
		}
	}
	for(int j = 0; j < n; j++) {
		ans = max(ans,dp[m - 1][j]);
	}
	return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>arr = {{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    cout << getMaxPathSum(arr) << nl;                 
    return 0;
}
*/

/*-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------*/

/*
//Space Optimization Method

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int getMaxPathSum(vector<vector<int>> &matrix) {
	int ans = INT_MIN;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int>prev(n,0),cur(n,0);
	for(int j = 0; j < n; j++) {
		prev[j] = matrix[0][j];
	}
	for(int i = 1; i < m; i++) {
		for(int j = 0; j < n; j++) {
			int up = matrix[i][j] + prev[j]; 
			int leftDiagonal = matrix[i][j];
			if(j - 1 >= 0) {
				leftDiagonal += prev[j - 1];
			}
			else {
				leftDiagonal += (-1e9);
			}
			int rightDiagonal = matrix[i][j];
			if(j + 1 < n) {
				rightDiagonal += prev[j + 1];
			}
			else {
				rightDiagonal += (-1e9);
			}
			cur[j] = max({up,leftDiagonal,rightDiagonal});
		}
		prev = cur;
	}
	for(int j = 0; j < n; j++) {
		ans = max(ans,prev[j]);
	}
	return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>arr = {{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    cout << getMaxPathSum(arr) << nl;                 
    return 0;
}
*/