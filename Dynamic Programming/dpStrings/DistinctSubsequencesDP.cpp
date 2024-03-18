//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int MOD = 1e9 + 7;
int fun(int i,int j,string &s,string &t) {
	if(j < 0) {
		return 1;
	}
	if(i < 0) {
		return 0;
	}
	if(s[i] == t[j]) {
		int leaveOne = fun(i - 1,j - 1,s,t);
		int stay = fun(i - 1,j,s,t);
		return (leaveOne + stay) % MOD;
	}
	else {
		return fun(i - 1,j,s,t);
	}
}
int numDistinct(string s, string t) {
	int m = s.size();
	int n = t.size();
	return fun(m - 1,n - 1,s,t);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	string s = "rabbbit";
	string t = "rabbit";
	cout << numDistinct(s,t) << nl;	
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
int MOD = 1e9 + 7;
int fun(int i,int j,string &s,string &t,vector<vector<int>>&dp) {
	if(j < 0) {
		return 1;
	}
	if(i < 0) {
		return 0;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if(s[i] == t[j]) {
		int leaveOne = fun(i - 1,j - 1,s,t,dp);
		int stay = fun(i - 1,j,s,t,dp);
		return dp[i][j] = (leaveOne + stay) % MOD;
	}
	else {
		return dp[i][j] = fun(i - 1,j,s,t,dp);
	}
}
int numDistinct(string s, string t) {
	int m = s.size();
	int n = t.size();
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return fun(m - 1,n - 1,s,t,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	string s = "rabbbit";
	string t = "rabbit";
	cout << numDistinct(s,t) << nl;	
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
int MOD = 1e9 + 7;
int numDistinct(string s, string t) {
	int m = s.size();
	int n = t.size();
	vector<vector<int>>dp(m + 1,vector<int>(n + 1,0));
	
	for(int i = 0; i < m + 1; i++) {
		dp[i][0] = 1;
	}
	for(int i = 1; i < n + 1; i++) {
		dp[0][i] = 0;
	}
	for(int i = 1; i < m + 1; i++) {
		for(int j = 1; j < n + 1; j++) {
			if(s[i - 1] == t[j - 1]) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[m][n];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	string s = "rabbbit";
	string t = "rabbit";
	cout << numDistinct(s,t) << nl;	
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
int MOD = 1e9 + 7;
int numDistinct(string s, string t) {
	int m = s.size();
	int n = t.size();
	
	vector<int>prev(n + 1,0);
	prev[0] = 1;
	
	for(int i = 1; i < m + 1; i++) {
		for(int j = n; j >= 1; j--) {
			if(s[i - 1] == t[j - 1]) {
				prev[j] = (prev[j - 1] + prev[j]) % MOD;
			}
			else {
				prev[j] = prev[j];
			}
		}
	}
	return prev[n];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout)	;
#endif
	string s = "rabbbit";
	string t = "rabbit";
	cout << numDistinct(s,t) << nl;	
    return 0;
}
*/