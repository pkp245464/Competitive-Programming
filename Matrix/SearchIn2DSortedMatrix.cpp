#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"  
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
    vector<int> search2DMatrix(vector<vector<int>>&nums,int target) {
        vector<int>pos(2,-1);
        int n = nums.size();
        int m = nums[0].size();
        int i = 0;
        int j = m - 1;
        while(i >= 0 && i < n && j >= 0 && j < m) {
            if(nums[i][j] == target) {
                pos[0] = i;
                pos[1] = j;
                return pos;
            }
            else if( target < nums[i][j]) {
                j--;
            }
            else if(target > nums[i][j]) {
                i++;
            }
        }
        return pos;
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p=new Solution();
    vector<vector<int>>arr{ {1,3,5,7},
                           {10,11,16,20},
                           {23,30,34,60} };
    int target=30;
    vector<int>ans = p->search2DMatrix(arr,target);
    cout<<"("<<ans[0]<<","<<ans[1]<<")"<<nl;
    return 0;
}