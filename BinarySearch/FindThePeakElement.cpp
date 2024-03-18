#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double   
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int findPeakElement(vector<int>&nums) {
	int n = nums.size();
	if(n == 1) return 0;
	int l = 0,h = n - 1;
	while(l <= h) {
		int mid = l + (h - l) / 2;
		if(mid > 0 && mid < n -1) {
			if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
				return mid;
			}
			else if(nums[mid - 1] > nums[mid] && nums[mid + 1]) {
				h = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		else if(mid == 0) {
			if(nums[0] > nums[1]) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else if(mid == n-1){
			if(nums[n - 1] > nums[n - 2]) {
				return n - 1;
			}
			else {
				return n - 2;
			}
		}
	}
	return -1;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr{5,11,13,19,27,30,40,7,6,5,4,1};
    cout << findPeakElement(arr) << nl; //O/P: 6 (index- 0 to n)
    return 0;
}