//Recursion Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int countWay(int i,int j) {
	if(i == 0 && j == 0) {
		return 1;
	}
	if(i < 0 || j < 0) {
		return 0;
	}
	int up = countWay(i- 1,j);
	int left = countWay(i,j - 1);
	return (up + left);
}
int uniquePaths(int m, int n) {
	return countWay(m - 1,n - 1);    
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m = 3, n = 7;
    cout << uniquePaths(m,n) << nl;  
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Top Down Approach (Meomoization)

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int countWay(int i,int j,vector<vector<int>>&dp) {
	if(i == 0 || j == 0) {
		return 1;
	}

	if(dp[i][j] != -1) return dp[i][j];

	int up = countWay(i- 1,j,dp);
	int left = countWay(i,j - 1,dp);

	return dp[i][j] = up + left;
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return countWay(m - 1,n - 1,dp);    
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m = 3, n = 7;
	cout << uniquePaths(m,n) << nl;	
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Bottom Top Approach (Tabulation)

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int countWay(int m,int n,vector<vector<int>>&dp) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
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
	return dp[m - 1][n - 1];
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return countWay(m,n,dp);   
}
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m = 3, n = 7;
	cout << uniquePaths(m,n) << nl;	
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space Optimization

int uniquePaths(int m, int n) {
	vector<int>prev(n,0);
	for(int i = 0; i < m; i++) {
		vector<int>temp(n,0);
		for(int j =0 ;j < n; j++) {
			if(i == 0 && j == 0) {
				temp[j] = 1;
				continue;
			}
			int up = 0;
			int left = 0;

			if(i > 0) {
				up = prev[j];
			}
			if(j > 0) {
				left = temp[j - 1];
			}
			temp[j] = up + left;
		}
		prev = temp;
	}
	return prev[n - 1];
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*

// Formula Based

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int uniquePaths(int m, int n) {
	long long ans = 1;
	for (int i = 1; i <= m - 1; i++) {
		ans = ans * (n - 1 + i) / i;
	}
	return (int)ans;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m = 3, n = 7;
	cout << uniquePaths(m,n) << nl;	
    return 0;
}
*/