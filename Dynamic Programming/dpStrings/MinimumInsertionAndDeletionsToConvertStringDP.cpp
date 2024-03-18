#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int longestCommonSubsequence(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	vector<vector<int>>dp(m + 1,vector<int>(n + 1,-1));
	for(int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}
	for(int i = 0; i <= n; i++) {
		dp[0][i] = 0;
	}
	for(int ind1 = 1; ind1 <= m; ind1++) {
		for(int ind2 = 1; ind2 <= n; ind2++) {
			if(s1[ind1 - 1] == s2[ind2 - 1]) {
				dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
			}
			else {
				dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2],dp[ind1][ind2 - 1]);
			}
		}
	}
	return dp[m][n];
}
int minInsertionAndDeletions(string s1,string s2) {
	int m = s1.size();
	int n = s2.size();
	int lcs = longestCommonSubsequence(s1,s2);
	return (m - lcs) + (n - lcs);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1 = "abcd";
    string s2 = "anc";
    cout << minInsertionAndDeletions(s1,s2) << nl;
    return 0;
}