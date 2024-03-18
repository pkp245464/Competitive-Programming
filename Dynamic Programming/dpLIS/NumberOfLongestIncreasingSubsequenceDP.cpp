#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int findNumberOfLIS(vector<int>&nums) {
	int n = nums.size();
	vector<int>dp(n,1),cnt(n,1);
	int maxi = 1;
	for(int i = 0; i < n; i++) {
		for(int prev = 0; prev < i; prev++) {
			if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
				dp[i] = 1 + dp[prev];
				cnt[i] = cnt[prev];
			}
			else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) {
				cnt[i] += cnt[prev];
			}
		}
		maxi = max(maxi,dp[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(dp[i] == maxi) {
			ans += cnt[i];
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
    vector<int>arr = {1,3,5,4,7};
    cout << findNumberOfLIS(arr) << nl;                      
    return 0;           
}               
