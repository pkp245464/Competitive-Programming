#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
ll kadaneAlgorithm(vector<int>&a) {
    ll sum = 0,maxi = -1e18;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i];
        maxi = max(maxi,sum);
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>a = {-2,-3,4,-1,-2,1,5,-3};
    cout << kadaneAlgorithm(a) << nl;
    return 0;
}


/*
//Maximum Sum Circular Subarray

using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int maxSubarraySumCircular(vector<int>& nums) {
	int maxi = INT_MIN,mini = INT_MAX,sum1 = 0,sum2 = 0,totalSum;
	totalSum = accumulate(nums.begin(),nums.end(),0);
	for(int i = 0; i < nums.size(); i++) {
		sum1 += nums[i];
		sum2 += nums[i];
		maxi = max(maxi,sum1);
		if(sum1 < 0) {
			sum1 = 0;
		}
		mini = min(mini,sum2);
		if(sum2 > 0) {
			sum2 = 0;
		}
	}
	return (totalSum == mini ? maxi : max({maxi,totalSum - mini}));
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {5,-3,5};
    cout << maxSubarraySumCircular(arr) << nl;         
    return 0;
}
*/