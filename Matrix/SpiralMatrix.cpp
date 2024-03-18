#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
vector<int> spiralOrder(vector<vector<int>>&nums) {
    int m = nums.size();
    int n = nums[0].size();
    int top = 0,left = 0,bottom = m - 1,right = n - 1;
    vector<int>ans;
    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
            ans.push_back(nums[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++) {
            ans.push_back(nums[i][right]);
        }
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                ans.push_back(nums[bottom][i]);
            }
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                ans.push_back(nums[i][left]);
            }
            left++;
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
    vector<vector<int>>nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int>ans = spiralOrder(nums);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

/*
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
Output: [1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]
*/