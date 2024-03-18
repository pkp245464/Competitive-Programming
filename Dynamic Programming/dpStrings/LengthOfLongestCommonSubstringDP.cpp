//Tabulation Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///  
int lcs(string s1,string s2) {
	int m = s1.size();
	int n = s2.size();
	vector<vector<int>>dp(m + 1,vector<int>(n + 1,0));
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s1[i - 1] == s2[j - 1]) {
				int val = 1 + dp[i - 1][j - 1];
				dp[i][j] = val;
				ans = max(ans,val);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1 = "abcjklp";
    string s2 = "acjkp";
    cout << lcs(s1,s2) << nl;
    return 0;
}

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
int lcs(string s1,string s2) {
	int m = s1.size();
	int n = s2.size();
	vector<int>prev(n + 1,0),cur(n + 1,0);
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s1[i - 1] == s2[j - 1]) {
				int val = 1 + prev[j - 1];
				cur[j] = val;
				ans = max(ans,val);
			}
			else {
				cur[j] = 0;
			}
		}
		prev = cur;
	}
	return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1 = "abcjklp";
    string s2 = "acjkp";
    cout << lcs(s1,s2) << nl;
    return 0;
}
*/