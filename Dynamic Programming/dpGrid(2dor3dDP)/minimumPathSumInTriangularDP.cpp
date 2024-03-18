// Recursive Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int i,int j,int n,vector<vector<int>>& triangle) {
	if(i == n - 1) {
		return triangle[i][j];
	}
	int down = triangle[i][j] + fun(i + 1,j,n,triangle);
	int diagonal = triangle[i][j] + fun(i + 1,j + 1,n,triangle);
	return min(down,diagonal);
}
int minimumTotal(vector<vector<int>>& triangle) {
	return fun(0,0,triangle.size(),triangle);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = { {2},{3,4},{6,5,7},{4,1,8,3}};
	cout << minimumTotal(arr) << nl;
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
int fun(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp) {
	if(i == n - 1) {
		return triangle[i][j];
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	int down = triangle[i][j] + fun(i + 1,j,n,triangle,dp);
	int diagonal = triangle[i][j] + fun(i + 1,j + 1,n,triangle,dp);
	return dp[i][j] = min(down,diagonal);
}
int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
	vector<vector<int>>dp(n,vector<int>(n,-1));
	return fun(0,0,triangle.size(),triangle,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = { {2},{3,4},{6,5,7},{4,1,8,3}};
	cout << minimumTotal(arr) << nl;
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
int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
	vector<vector<int>>dp(n,vector<int>(n,0));
	for(int i = 0; i < n; i++) {
		dp[n - 1][i] = triangle[n - 1][i];
	}
	for(int i = n - 2; i >= 0; i--) {
		for(int j = i; j >= 0; j--) {
			int down = triangle[i][j] + dp[i + 1][j];
			int diagonal = triangle[i][j] + dp[i + 1][j + 1];
			dp[i][j] = min(down,diagonal);
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
	vector<vector<int>>arr = { {2},{3,4},{6,5,7},{4,1,8,3}};
	cout << minimumTotal(arr) << nl;
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
int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
	vector<int>front(n,0),cur(n,0);
	for(int i = 0; i < n; i++) {
		front[i] = triangle[n - 1][i];
	}
	for(int i = n - 2; i >= 0; i--) {
		for(int j = i; j >= 0; j--) {
			int down = triangle[i][j] + front[j];
			int diagonal = triangle[i][j] + front[j + 1];
			cur[j] = min(down,diagonal);
		}
		front = cur;
	}
	return front[0];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>arr = { {2},{3,4},{6,5,7},{4,1,8,3}};
	cout << minimumTotal(arr) << nl;
    return 0;
}
*/