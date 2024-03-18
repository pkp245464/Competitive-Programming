//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
bool isPalindrome(int i,int j,string &s) {
	while(i < j) {
		if(s[i] != s[j]) {
			return false;
		}
		i++,j--;
	}
	return true;
}
int fun(int i,int n,string &s) {
	if(i == n) {
		return 0;
	}
	int minCost = INT_MAX;
	for(int j = i; j < n; j++) {
		if(isPalindrome(i,j,s)) {
			int cost = 1 + fun(j + 1,n,s);
			minCost = min(minCost,cost);
		}
	}
	return minCost;
}
int minCut(string s) {
	return fun(0,s.size(),s) - 1;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "aab";
    cout << minCut(s)<<nl;    
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
bool isPalindrome(int i,int j,string &s) {
	while(i < j) {
		if(s[i] != s[j]) {
			return false;
		}
		i++,j--;
	}
	return true;
}
int fun(int i,int n,string &s,vector<int>&dp) {
	if(i == n) {
		return 0;
	}
	if(dp[i] != -1) {
		return dp[i];
	}
	int minCost = INT_MAX;
	for(int j = i; j < n; j++) {
		if(isPalindrome(i,j,s)) {
			int cost = 1 + fun(j + 1,n,s,dp);
			minCost = min(minCost,cost);
		}
	}
	return dp[i] = minCost;
}
int minCut(string s) {
	int n = s.size();
	vector<int>dp(n,-1);
	return fun(0,s.size(),s,dp) - 1;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "aab";
    cout << minCut(s) << nl;    
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
bool isPalindrome(int i,int j,string &s) {
	while(i < j) {
		if(s[i] != s[j]) {
			return false;
		}
		i++,j--;
	}
	return true;
}
int minCut(string s) {
	int n = s.size();
	vector<int>dp(n + 1,0);
	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--) {
		int minCost = INT_MAX;
		for(int j = i; j < n; j++) {
			if(isPalindrome(i,j,s)) {
				int cost = 1 + dp[j + 1];
				minCost = min(minCost,cost);
			}
		}
		dp[i] = minCost;
	}
	return dp[0] - 1;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "aab";
    cout << minCut(s) << nl;    
    return 0;
}
*/