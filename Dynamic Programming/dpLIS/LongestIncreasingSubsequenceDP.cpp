//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int prev,vector<int>&arr) {
	if(ind == arr.size()) {
		return 0;
	}
	int notTake = 0 + fun(ind + 1,prev,arr);
	int take = 0;
	if(prev == -1 || arr[ind] > arr[prev]) {
		take = 1 + fun(ind + 1,ind,arr);
	}
	return max(take,notTake);
}
int lengthOfLIS(vector<int>&arr) {
	return fun(0,-1,arr);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(arr) << nl;            
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Meoization Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int prev,vector<int>&arr,vector<vector<int>>&dp) {
	if(ind == arr.size()) {
		return 0;
	}
	if(dp[ind][prev + 1] != -1) {
		return dp[ind][prev + 1];
	}
	int notTake = 0 + fun(ind + 1,prev,arr,dp);
	int take = 0;
	if(prev == -1 || arr[ind] > arr[prev]) {
		take = 1 + fun(ind + 1,ind,arr,dp);
	}
	return dp[ind][prev + 1] = max(take,notTake);
}
int lengthOfLIS(vector<int>&arr) {
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(n + 1,-1));
	return fun(0,-1,arr,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(arr) << nl;            
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
int lengthOfLIS(vector<int>&arr) {
	int n = arr.size();
	vector<vector<int>>dp(n + 1,vector<int>(n + 1,0));
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int prev = n - 1; prev >= -1; prev--) {
			int notTake = 0 + dp[ind + 1][prev + 1];
			int take = 0;
			if(prev == -1 || arr[ind] > arr[prev]) {
				take = 1 + dp[ind + 1][ind + 1];
			}
			dp[ind][prev + 1] = max(take,notTake);
		}
	}
	return dp[0][0];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(arr) << nl;            
    return 0;
}
*/

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
int lengthOfLIS(vector<int>&arr) {
	int n = arr.size();
	vector<int>next(n + 1,0),cur(n + 1,0);
	for(int ind = n - 1; ind >= 0; ind--) {
		for(int prev = n - 1; prev >= -1; prev--) {
			int notTake = 0 + next[prev + 1];
			int take = 0;
			if(prev == -1 || arr[ind] > arr[prev]) {
				take = 1 + next[ind + 1];
			}
			cur[prev + 1] = max(take,notTake);
		}
		next = cur;
	}
	return cur[0];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(arr) << nl;            
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Binary Search Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int>temp;
	temp.push_back(nums[0]);
	int len = 1;
	for(int i = 1; i < n; i++) {
		if(nums[i] > temp.back()) {
			temp.push_back(nums[i]);
			len++;
		}
		else {
			int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
			temp[ind] = nums[i];
		}
	}
	return len;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {10,9,2,5,3,7,101,18};
	cout << lengthOfLIS(arr) << nl;
    return 0;
}
*/
