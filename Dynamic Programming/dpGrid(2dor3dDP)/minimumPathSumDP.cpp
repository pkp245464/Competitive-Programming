// Recursive Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int i,int j,vector<vector<int>>&grid) {
	if(i == 0 && j == 0) {
		return grid[0][0];
	}
	if(i < 0 || j < 0) {
		return 1e9;
	}
	int up = grid[i][j] + fun(i - 1,j,grid);
	int left = grid[i][j] + fun(i,j - 1,grid);
	return min(up,left);
}
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	return fun(m - 1, n - 1,grid);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = {{1,3,1},
					         {1,5,1},
					         {4,2,1}};
	cout << minPathSum(arr) << nl;
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
int fun(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp) {
	if(i == 0 && j == 0) {
		return grid[0][0];
	}
	if(i < 0 || j < 0) {
		return 1e9;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	int up = grid[i][j] + fun(i - 1,j,grid,dp);
	int left = grid[i][j] + fun(i,j - 1,grid,dp);
	return dp[i][j] = min(up,left);
}
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return fun(m - 1, n - 1,grid,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = {{1,3,1},
					         {1,5,1},
					         {4,2,1}};
	cout << minPathSum(arr) << nl;
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
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>>dp(m,vector<int>(n,0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(i == 0 && j == 0) {
				dp[i][j] = grid[i][j];
			}
			else {
				int up = grid[i][j];
				if(i > 0) {
					up += dp[i - 1][j];
				}
				else {
					up += 1e9;
				}
				int left = grid[i][j];
				if(j > 0) {
					left += dp[i][j - 1];
				}
				else {
					left += 1e9;
				}
				dp[i][j] = min(up,left);
			}
		}
	}
	return dp[m - 1][n - 1];
}

int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = {{1,3,1},
					          {1,5,1},
					          {4,2,1}};
	cout << minPathSum(arr) << nl;
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
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<int>prev(n,0);
	for(int i = 0; i < m; i++) {
		vector<int>temp(n,0);
		for(int j = 0; j < n; j++) {
			if(i == 0 && j == 0) {
				temp[j] = grid[i][j];
			}
			else {
				int up = grid[i][j];
				if(i > 0) {
					up += prev[j];
				}
				else {
					up += 1e9;
				}
				int left = grid[i][j];
				if(j > 0) {
					left += temp[j - 1];
				}
				else {
					left += 1e9;
				}
				temp[j] = min(up,left);
			}
		}
		prev = temp;
	}
	return prev[n - 1];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = {{1,3,1},
							 {1,5,1},
					         {4,2,1}};
	cout << minPathSum(arr) << nl;
    return 0;
}
*/