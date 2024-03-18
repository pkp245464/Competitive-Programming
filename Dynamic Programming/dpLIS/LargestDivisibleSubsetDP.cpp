//Printing The Longest Increassing Subsequence based

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
vector<int> largestDivisibleSubset(vector<int>& nums) {
	int n = nums.size();
	vector<int>dp(n,1),hash(n);
	int maxi = 1;
	int lastIndex = 0;
	sort(nums.begin(),nums.end());
	for(int i = 0; i < n; i++) {
		hash[i] = i;
		for(int prev = 0; prev < i; prev++) {
			if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) {
				dp[i] = 1 + dp[prev];
				hash[i] = prev;
			}
		}
		if(dp[i] > maxi) {
			maxi = dp[i];
			lastIndex = i;
		}
	}
	vector<int>temp;
	temp.push_back(nums[lastIndex]);
	while(hash[lastIndex] != lastIndex) {
		lastIndex = hash[lastIndex];
		temp.push_back(nums[lastIndex]);
	}
	reverse(temp.begin(),temp.end());
	return temp;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {1,2,4,8};
	vector<int>ans = largestDivisibleSubset(arr);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i]<< " ";
	}
    return 0;
}