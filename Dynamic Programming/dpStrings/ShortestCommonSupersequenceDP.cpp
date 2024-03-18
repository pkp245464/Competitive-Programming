#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
string shortestCommonSupersequence(string s1, string s2) {
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
	int len = dp[m][n];
	int i = m;
	int j = n;
	int ind = len - 1;
	string ans = "";

	while(i > 0 && j > 0) {
		if(s1[i - 1] == s2[j - 1]) {
			ans += s1[i - 1];
			ind--,i--,j--;
		}
		else if(dp[i - 1][j] > dp[i][j - 1]) {
			ans += s1[i - 1];
			i--;
		}
		else {
			ans += s2[j - 1];
			j--;
		}
	}
	while(i > 0) {
		ans += s1[i - 1];
		i--;
	}
	while(j > 0) {
		ans += s2[j - 1];
		j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;    
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1 = "abac";
    string s2 = "cab";
    cout << shortestCommonSupersequence(s1,s2) << nl;
    return 0;
}