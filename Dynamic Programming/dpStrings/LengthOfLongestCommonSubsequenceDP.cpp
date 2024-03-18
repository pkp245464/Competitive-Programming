//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind1,int ind2,string &s1,string &s2) {
	if(ind1 < 0 || ind2 < 0) {
		return 0;
	}
	if(s1[ind1] == s2[ind2]) {
		return 1 + fun(ind1 - 1,ind2 - 1,s1,s2);
	}
	else {
		return 0 + max(fun(ind1 - 1,ind2,s1,s2),fun(ind1,ind2 - 1,s1,s2));
	}
}
int longestCommonSubsequence(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	return fun(m - 1,n - 1,s1,s2);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1 = "abcde";
    string s2 = "ace";
    cout << longestCommonSubsequence(s1,s2) << nl;
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
int fun(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp) {
	if(ind1 < 0 || ind2 < 0) {
		return 0;
	}
	if(dp[ind1][ind2] != -1) {
		return dp[ind1][ind2];
	}
	if(s1[ind1] == s2[ind2]) {
		return 1 + fun(ind1 - 1,ind2 - 1,s1,s2,dp);
	}
	else {
		return dp[ind1][ind2] = 0 + max(fun(ind1 - 1,ind2,s1,s2,dp),fun(ind1,ind2 - 1,s1,s2,dp));
	}
}
int longestCommonSubsequence(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return fun(m - 1,n - 1,s1,s2,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1 = "abcde";
    string s2 = "ace";
    cout << longestCommonSubsequence(s1,s2) << nl;
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
int longestCommonSubsequence(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	vector<vector<int>>dp(m + 1,vector<int>(n + 1,0));
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
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1 = "abcde";
    string s2 = "ace";
    cout << longestCommonSubsequence(s1,s2) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space Optimization Method

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
	vector<int>prev(n + 1,0),cur(n + 1,0);

	for(int ind1 = 1; ind1 <= m; ind1++) {
		for(int ind2 = 1; ind2 <= n; ind2++) {
			if(s1[ind1 - 1] == s2[ind2 - 1]) {
				cur[ind2] = 1 + prev[ind2 - 1];
			}
			else {
				cur[ind2] = 0 + max(prev[ind2],cur[ind2 - 1]);
			}
		}
		prev = cur;
	}
	return prev[n];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1 = "abcde";
    string s2 = "ace";
    cout << longestCommonSubsequence(s1,s2) << nl;
    return 0;
}
*/