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
    vector<int> stockSpan(vector<int>&nums) {
        vector<int>ans;
        stack<pair<int,int>>st;
        for(int i = 0; i < nums.size(); i++) {
            if(st.size() == 0) {
                ans.push_back(-1);
            }
            else if(st.size() > 0 && st.top().first > nums[i]) {
                ans.push_back(st.top().second);
            }
            else if(st.size() > 0 && st.top().first <= nums[i]) {
                while(st.size() > 0 && st.top().first <= nums[i]) {
                    st.pop();
                }
                if(st.size() == 0) {
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(st.top().second);
                }
            }
            st.push({nums[i],i});
        }
        for(int i = 0 ;i < ans.size(); i++) {
            ans[i] = i - ans[i];
        }
        return ans;
    }
};
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p=new Solution();
    vector<int>arr = {100,80,60,70,60,75,85};
    vector<int>ans = p->stockSpan(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
