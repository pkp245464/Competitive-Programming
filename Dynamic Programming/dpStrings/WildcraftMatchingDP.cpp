//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
bool isAllStars(string &p,int i) {
	for(int j = 0; j <= i; j++) {
		if(p[j] != '*') {
			return false;
		}
	}
	return true;
}
int fun(int i,int j,string &p,string &t) {
	if(i < 0 && j < 0) {
		return true;
	}
	if(i < 0 && j >= 0) {
		return false;
	}
	if(j < 0 && i >= 0) {
		return isAllStars(p,i);
	}
	if(p[i] == t[j] || p[i] == '?') {
		return fun(i - 1,j - 1,p,t);
	}
	if(p[i] == '*') {
		return fun(i - 1,j,p,t) || fun(i,j - 1,p,t);
	}
	return false;
}
bool wildcardMatching(string p, string t) {
	int m = p.size(); 
	int n = t.size();
	return fun(m - 1,n - 1,p,t);
}

int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string pattern = "*";
    string text = "cb";
    cout << wildcardMatching(pattern,text) << nl;
    return 0;
}
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Memoization Method

//Zero Based Index

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
bool isAllStars(string &p,int i) {
    for(int j = 0; j <= i; j++) {
        if(p[j] != '*') {
            return false;
        }
    }
    return true;
}
int fun(int i,int j,string &p,string &t,vector<vector<int>>&dp) {
    if(i < 0 && j < 0) {
        return true;
    }
    if(i < 0 && j >= 0) {
        return false;
    }
    if(j < 0 && i >= 0) {
        return isAllStars(p,i);
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(p[i] == t[j] || p[i] == '?') {
        return dp[i][j] = fun(i - 1,j - 1,p,t,dp);
    }
    if(p[i] == '*') {
        return dp[i][j] = fun(i - 1,j,p,t,dp) | fun(i,j - 1,p,t,dp);
    }
    return dp[i][j] = false;
}
bool wildcardMatching(string p, string t) {
    int m = p.size(); 
    int n = t.size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return fun(m - 1,n - 1,p,t,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string pattern = "ab*cd";
    string text = "abdefcd";
    cout << wildcardMatching(pattern,text) << nl;
    return 0;
}

//One Based Index
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int i,int j,string &p,string &t,vector<vector<int>>&dp) {
	if(i == 0 && j == 0) {
		return true;
	}
	if(i == 0 && j > 0) {
		return false;
	}
	if(j == 0 && i > 0) {
		for(int ind = 1; ind <= i; ind++) {
			if(p[ind - 1] != '*') {
				return false;
			}
		}
		return true;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if(p[i - 1] == t[j - 1] || p[i - 1] == '?') {
		return dp[i][j] = fun(i - 1,j - 1,p,t,dp);
	}
	if(p[i - 1] == '*') {
		return dp[i][j] = fun(i - 1,j,p,t,dp) | fun(i,j - 1,p,t,dp);
	}
	return dp[i][j] = false;
}
bool wildcardMatching(string p, string t) {
	int m = p.size(); 
	int n = t.size();
	vector<vector<int>>dp(m + 1,vector<int>(n + 1,-1));
	return fun(m,n,p,t,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string pattern = "*";
    string text = "cb";
    cout << wildcardMatching(pattern,text) << nl;
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
bool wildcardMatching(string p, string t) {
	int m = p.size(); 
	int n = t.size();
	vector<vector<bool>>dp(m + 1,vector<bool>(n + 1,0));

	dp[0][0] = true;
	for(int i = 1; i <= n; i++) {
		dp[0][i] = false;
	}

	for(int i = 1; i <= m; i++) {
		int flag = true;
		for(int j = 1; j <= i; j++) {
			if(p[j - 1] != '*') {
				flag = false;
				break;
			}
		}
		dp[i][0] = flag;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(p[i - 1] == t[j - 1] || p[i - 1] == '?') {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if(p[i - 1] == '*') {
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; 
			}
			else {
				dp[i][j] = false;
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
    string pattern = "?kb*zx";
    string text = "akbcdksz";
    cout << wildcardMatching(pattern,text) << nl;
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
bool wildcardMatching(string p, string t) {
	int m = p.size(); 
	int n = t.size();
	vector<bool>prev(n + 1,false),cur(n + 1,false);

	prev[0] = true;
	for(int i = 1; i <= n; i++) {
		prev[i] = false;
	}

	for(int i = 1; i <= m; i++) {
		int flag = true;
		for(int j = 1; j <= i; j++) {
			if(p[j - 1] != '*') {
				flag = false;
				break;
			}
		}
		cur[0] = flag;

		for(int j = 1; j <= n; j++) {
			if(p[i - 1] == t[j - 1] || p[i - 1] == '?') {
				cur[j] = prev[j - 1];
			}
			else if(p[i - 1] == '*') {
				cur[j] = prev[j] || cur[j - 1]; 
			}
			else {
				cur[j] = false;
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
    string pattern = "*";
    string text = "cb";
    cout << wildcardMatching(pattern,text) << nl;
    return 0;
}
*/