//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int i,int j,string &s,string &t) {
	if(i < 0) {
		return j + 1;
	}
	if(j < 0) {
		return i + 1;
	}
	if(s[i] == t[j]) {
		return 0 + fun(i - 1,j - 1,s,t);
	}
	else {
		return 1 + min(fun(i - 1,j - 1,s,t),min(fun(i - 1,j,s,t),fun(i,j - 1,s,t)));
	}
}
int minDistance(string s, string t) {
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
	string s = "intention";
	string t = "execution";
	cout << minDistance(s,t) << nl;	
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
int fun(int i,int j,string &s,string &t,vector<vector<int>>&dp) {
	if(i < 0) {
		return j + 1;
	}
	if(j < 0) {
		return i + 1;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if(s[i] == t[j]) {
		return dp[i][j] = 0 + fun(i - 1,j - 1,s,t,dp);
	}
	else {
		return dp[i][j] = 1 + min(fun(i - 1,j - 1,s,t,dp),min(fun(i - 1,j,s,t,dp),fun(i,j - 1,s,t,dp)));
	}
}
int minDistance(string s, string t) {
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
	string s = "intention";
	string t = "execution";
	cout << minDistance(s,t) << nl;	
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
int minDistance(string s, string t) {
	int m = s.size();
	int n = t.size();
	vector<vector<int>>dp(m + 1,vector<int>(n + 1,0));
	
	for(int i = 0; i <= m; i++) {
		dp[i][0] = i;
	}
	for(int j = 0; j <= n; j++) {
		dp[0][j] = j;
	}
	for(int i = 1; i < m + 1; i++) {
		for(int j = 1; j < n + 1; j++) {
			if(s[i - 1] == t[j - 1]) {
				dp[i][j] = 0 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min(dp[i - 1][j - 1],min(dp[i - 1][j],dp[i][j - 1]));
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
	string s = "intention";
	string t = "execution";
	cout << minDistance(s,t) << nl;	
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
int minDistance(string s, string t) {
	int m = s.size();
	int n = t.size();
	
	vector<int>prev(n + 1,0),cur(n + 1,0);
	
	for(int i = 0; i <= n; i++) {
		prev[i] = i;
	}
	
	for(int i = 1; i < m + 1; i++) {
		cur[0] = i;
		for(int j = 1; j < n + 1; j++) {
			if(s[i - 1] == t[j - 1]) {
				cur[j] = 0 + prev[j - 1];
			}
			else {
				cur[j] = 1 + min(prev[j - 1],min(prev[j],cur[j - 1]));
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
	freopen("output.txt", "w", stdout)	;
#endif
	string s = "intention";
	string t = "execution";
	cout << minDistance(s,t) << nl;	
    return 0;
}
*/