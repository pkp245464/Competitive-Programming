//Based on Longest Increasing Subsequence

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
static bool comparator(string &s,string &t) {
	return s.size() < t.size();
}
bool checkPossible(string &s,string &t) {
	if(s.size() != t.size() + 1) {
		return false;
	}
	int first = 0,second = 0;
	while(first < s.size()) {
		if(s[first] == t[second]) {
			first++,second++;
		}
		else if(second == t.size()) {
			return true;
		}
		else {
			first++;
		}
	}
	if(first == s.size() && second == t.size()) {
		return true;
	}
	else {
		return false;
	}
}
int longestStrChain(vector<string>& nums) {
	int n = nums.size();
	vector<int>dp(n,1);
	int maxi = 1;
	sort(nums.begin(),nums.end(),comparator);
	for(int i = 0; i < n; i++) {
		for(int prev = 0; prev < i; prev++) {
			if(checkPossible(nums[i],nums[prev]) && 1 + dp[prev] > dp[i]) {
				dp[i] = 1 + dp[prev];
			}
		}
		maxi = max(maxi,dp[i]);
	}
	return maxi;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<string>vs = {"a","b","ba","bca","bda","bdca"};
	cout << longestStrChain(vs) << nl;
    return 0;
}