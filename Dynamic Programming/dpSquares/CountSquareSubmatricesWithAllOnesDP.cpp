#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int countSquares(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>>dp(m,vector<int>(n,0));
	for(int i = 0; i < n; i++) {
		dp[0][i] = matrix[0][i];
	}
	for(int i = 0; i < m; i++) {
		dp[i][0] = matrix[i][0];
	}
	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			if(matrix[i][j] == 0) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = 1 + min({dp[i - 1][j],dp[i - 1][j - 1],dp[i][j - 1]});
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			sum += dp[i][j];
		}
	}
	return sum;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>arr = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    cout << countSquares(arr) << nl;  
    return 0;
}
