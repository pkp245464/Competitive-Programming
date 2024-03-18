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
    vector<int> distinctElementKSizeWindow(int k,vector<int>&nums) {
        vector<int>ans;
        unordered_map<int,int>m;
        int i = 0,j = 0;
        while(j  < nums.size()) {
            m[nums[j]]++;
            if(j - i + 1 == k) {
                ans.push_back(m.size());
                m[nums[i]]--;
                if(m[nums[i]] == 0) {
                    m.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    vector<int>arr = {1,2,1,3,4,2,3};
    int k = 4;
    vector<int>ans = p->distinctElementKSizeWindow(k,arr);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;

}