//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int i,int j1,int j2,vector<vector<int>>&grid) {
	if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) {
		return -1e9;
	}
	if(i == grid.size() - 1) {
		if(j1 == j2) {
			return grid[i][j1];
		}
		else {
			return grid[i][j1] + grid[i][j2];
		}
	}
	int maxi = 0;
	for(int x = -1; x <= 1; x++) {
		for(int y = -1; y <= 1; y++) {
			int val;
			if(j1 == j2) {
				val  = grid[i][j1] + fun(i + 1,j1 + x,j2 + y,grid);
			} 
			else {
				val = grid[i][j1] + grid[i][j2] + fun(i + 1,j1 + x,j2 + y,grid);
			}
			maxi = max(maxi,val);
		}
	}
	return maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	return fun(0,0,n - 1,grid);    
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>arr = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << cherryPickup(arr) << nl;
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
int fun(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp) {
	if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) {
		return -1e9;
	}
	if(i == grid.size() - 1) {
		if(j1 == j2) {
			return grid[i][j1];
		}
		else {
			return grid[i][j1] + grid[i][j2];
		}
	}
	if(dp[i][j1][j2] != -1) {
		return dp[i][j1][j2];
	}
	int maxi = 0;
	for(int x = -1; x <= 1; x++) {
		for(int y = -1; y <= 1; y++) {
			int val;
			if(j1 == j2) {
				val  = grid[i][j1] + fun(i + 1,j1 + x,j2 + y,grid,dp);
			} 
			else {
				val = grid[i][j1] + grid[i][j2] + fun(i + 1,j1 + x,j2 + y,grid,dp);
			}
			maxi = max(maxi,val);
		}
	}
	return dp[i][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
	return fun(0,0,n - 1,grid,dp);    
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>arr = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << cherryPickup(arr) << nl;
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
int cherryPickup(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
	for(int j1 = 0; j1 < n; j1++) {
		for(int j2 = 0; j2 < n; j2++) {
			if(j1 == j2) {
				dp[m - 1][j1][j2] = grid[m - 1][j1];
			}
			else {
				dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
			}
		}
	} 
	for(int i = m - 2; i >= 0; i--) {
		for(int j1 = 0; j1 < n; j1++) {
			for(int j2 = 0; j2 < n; j2++) {
				int maxi = INT_MIN;
				for(int x = -1; x <= 1; x++) {
					for(int y = -1; y <= 1; y++) {
						int ans;
						if(j1 == j2) {
							ans = grid[i][j1];
						}
						else {
							ans = grid[i][j1] + grid[i][j2];
						}
						if((j1 + x < 0 || j1 + x >= n) || (j2 + y < 0 || j2 + y >= n)) {
							ans += -1e9;
						}
						else {
							ans += dp[i + 1][j1 + x][j2 + y];
						}
						maxi = max(ans,maxi);
					}
				}
				dp[i][j1][j2] = maxi;
			}
		}
	}            
	return dp[0][0][n - 1];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>arr = { {3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << cherryPickup(arr) << nl;
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
int cherryPickup(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>>front(n,vector<int>(n,0));
	vector<vector<int>>cur(n,vector<int>(n,0));
	for(int j1 = 0; j1 < n; j1++) {
		for(int j2 = 0; j2 < n; j2++) {
			if(j1 == j2) {
				front[j1][j2] = grid[m - 1][j1];
			}
			else {
				front[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
			}
		}
	} 
	for(int i = m - 2; i >= 0; i--) {
		for(int j1 = 0; j1 < n; j1++) {
			for(int j2 = 0; j2 < n; j2++) {
				int maxi = INT_MIN;
				for(int di = -1; di <= 1; di++) {
					for(int dj = -1; dj <= 1; dj++) {
						int ans;
						if(j1 == j2) {
							ans = grid[i][j1];
						}
						else {
							ans = grid[i][j1] + grid[i][j2];
						}
						if((j1 + di < 0 || j1 + di >= n) || (j2 + dj < 0 || j2 + dj >= n)) {
							ans += -1e9;
						}
						else {
							ans += front[j1 + di][j2 + dj];
						}
						maxi = max(ans,maxi);
					}
				}
				cur[j1][j2] = maxi;
			}
		}
		front = cur;
	}            
	return front[0][n - 1];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>arr = { {3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << cherryPickup(arr) << nl;
    return 0;
}
*/