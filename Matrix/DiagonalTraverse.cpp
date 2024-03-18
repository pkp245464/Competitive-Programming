#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int N = 1e5 + 3;
vector<vector<int>>pos(N);
vector<int> findDiagonalOrder(vector<vector<int>>&nums) {
    vector<int>ans;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < nums[i].size(); j++) {
            pos[i + j].push_back(nums[i][j]);
        }
    }
    for(int i = 0; i < N; i++) {
        while(pos[i].size()) {
            ans.push_back(pos[i].back());
            pos[i].pop_back();
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
    vector<vector<int>>nums = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    vector<int>ans = findDiagonalOrder(nums);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

/*
Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
*/