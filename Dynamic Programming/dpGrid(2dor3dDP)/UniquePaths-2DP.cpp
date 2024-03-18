//Recursive Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int cntWays(int i,int j,vector<vector<int>>&arr) {
	if(i >= 0 && j >= 0 && arr[i][j] == 1) {
		return 0;
	}
	if(i == 0 && j == 0) {
		return 1;
	}
	if(i < 0 || j < 0) {
		return 0;
	}
	int up = cntWays(i - 1,j,arr);
	int left = cntWays(i ,j - 1,arr);
	return up + left;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	return cntWays(m - 1,n - 1,obstacleGrid);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = { {0,0,0},
							   {0,1,0},
							   {0,0,0} };
	cout << uniquePathsWithObstacles(arr) << nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Memoization Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int cntWays(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp) {
	if(i >= 0 && j >= 0 &&  arr[i][j] == 1) {
		return 0;
	}
	if(i == 0 && j == 0) {
		return 1;
	}
	if(i < 0 || j < 0) {
		return 0;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	int up = cntWays(i - 1,j,arr,dp);
	int left = cntWays(i,j - 1,arr,dp);
	return dp[i][j] = up + left;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return cntWays(m - 1,n - 1,obstacleGrid,dp);    
}

int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = { {0,0} };
	cout << uniquePathsWithObstacles(arr) << nl;
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
int cntWays(int m,int n,vector<vector<int>>&arr,vector<vector<int>>&dp) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(i >= 0 && j >= 0 && arr[i][j] == 1) {
				dp[i][j] = 0;
				continue;
			}
			if(i == 0 && j == 0) {
				dp[i][j] = 1;
				continue;
			}
			int up = 0;
			int left = 0;
			if(i > 0) {
				up = dp[i - 1][j];
			}
			if(j > 0) {
				left = dp[i][j - 1];
			}
			dp[i][j] = up + left;
		}
	}
	return dp[m -1][n - 1];
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return cntWays(m,n,obstacleGrid,dp);        
}
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = { {0,0} };
	cout << uniquePathsWithObstacles(arr) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Space Optimization Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<int>prev(n,0);
	for(int i = 0; i < m; i++) {
		vector<int>temp(n,0);
		for(int j = 0; j < n; j++) {
			if(obstacleGrid[i][j] == 1) {
				temp[j] = 0;
			}
			else if(i == 0 && j == 0) {
				temp[j] = 1;
			}
			else {
				int up = 0,left = 0;
				if(i > 0) {
					up = prev[j];
				}
				if(j > 0) {
					left = temp[j - 1];
				}
				temp[j] = up + left;
			}
		}
		prev = temp;
	}
	return prev[n - 1];
}
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = { {0,1} };
	cout << uniquePathsWithObstacles(arr) << nl;
    return 0;
}
*/


