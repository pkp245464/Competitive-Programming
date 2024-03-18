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
int longestPalindrome(string s) {
	string t = s;
	reverse(s.begin(),s.end());
	return longestCommonSubsequence(s,t);
}
int minInsertions(string s) {
	return s.size() - longestPalindrome(s);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "abcaa";
    cout << minInsertions(s) << nl;
    return 0;
}