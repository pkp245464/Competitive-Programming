#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int missingNumber(vector<int>&nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); i++) {
        ans ^= nums[i] ^ (i + 1);
    } 
    return ans;
}  
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {3,0,1};
    cout << missingNumber(nums) << nl; // O/P: 2 is missing from 0 to 3 range
    return 0;
}