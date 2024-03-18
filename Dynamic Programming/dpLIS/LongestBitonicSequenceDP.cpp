#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int longestBitonicSequence(vector<int>&nums) {
	int n = nums.size();
	vector<int>dp1(n,1);
	for(int i = 0; i < n; i++) {
		for(int prev = 0; prev < i; prev++) {
			if(nums[prev] < nums[i] && 1 + dp1[prev] > dp1[i]) {
				dp1[i] = 1 + dp1[prev];
			}
		}
	}
	vector<int>dp2(n,1);
	for(int i = n - 1; i >= 0; i--) {
		for(int prev = n - 1; prev > i; prev--) {
			if(nums[prev] < nums[i] && 1 + dp2[prev] > dp2[i]) {
				dp2[i] = 1 + dp2[prev];
			}
		}
	}
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		maxi = max(maxi,dp1[i] + dp2[i] - 1);
	}
	return maxi;
} 
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {12,11,40,5,3,1};
	cout << longestBitonicSequence(arr) << nl;
    return 0;
}