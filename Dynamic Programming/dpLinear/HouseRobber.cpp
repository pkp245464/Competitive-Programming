//Using Recursion

#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,vector<int>&nums) {
	if(ind == 0) {
		return nums[ind];
	}
	if(ind < 0) {
		return 0;
	}
	int pick = nums[ind] + fun(ind - 2,nums);
	int notPick = 0 + fun(ind - 1,nums);
	return max(pick,notPick);
}
int rob(vector<int>& nums) {
	int n = nums.size();
	return fun(n - 1,nums);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << rob(arr) << nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Using Memoization Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,vector<int>&nums,vector<int>&dp) {
	if(ind == 0) {
		return nums[ind];
	}
	if(ind < 0) {
		return 0;
	}
	if(dp[ind] != -1) {
		return dp[ind];
	}
	int pick = nums[ind] + fun(ind - 2,nums,dp);
	int notPick = 0 + fun(ind - 1,nums,dp);
	return dp[ind] = max(pick,notPick);
}
int rob(vector<int>& nums) {
	int n = nums.size();
	vector<int>dp(n,-1);
	return fun(n - 1,nums,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << rob(arr) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Using Tabulation Approach

#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int rob(vector<int>& nums) {
	int n = nums.size();
	vector<int>dp(n,0);
	dp[0] = nums[0];
	for(int i = 1; i < n; i++) {
		int pick = nums[i];
		if(i > 1) {
			pick += dp[i - 2];
		}
		int notPick = 0 + dp[i - 1];
		dp[i] = max(pick,notPick);
	}
	return dp[n - 1];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << rob(arr) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space Optimization

#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int rob(vector<int>& nums) {
	int n = nums.size();
	int prev1,prev2 = 0;
	prev1 = nums[0];
	for(int i = 1; i < n; i++) {
		int pick = nums[i];
		if(i > 1) {
			pick += prev2;
		}
		int notPick = 0 + prev1;
		int cur = max(pick,notPick);
		prev2 = prev1;
		prev1 = cur;
	}
	return prev1;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << rob(arr) << nl;
    return 0;
}
*/