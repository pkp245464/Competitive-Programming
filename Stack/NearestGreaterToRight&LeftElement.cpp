// Nearest Greater To Right Element (Next Longest Elelement)
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
    vector<int> nextLargestElementRight(vector<int>&nums) {
        stack<int>st;
        vector<int>ans;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(st.size() == 0) {
                ans.push_back(-1);
            }
            else if(st.size() > 0 && st.top() > nums[i]) {
                ans.push_back(st.top());
            }
            else if(st.size() > 0 && st.top() <= nums[i]) {
                while(st.size() > 0 && st.top() <= nums[i]) {
                    st.pop();
                }
                st.size() == 0 ? ans.push_back(-1) : ans.push_back(st.top());
            }
            st.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
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
    vector<int>arr{1,3,0,0,1,2,4};
    vector<int>ans = p->nextLargestElementRight(arr);
    for(int i =0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";  
    }
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

// Nearest Greater To Left Element 
/*
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
    vector<int> nextLargestElementLeft(vector<int>&nums) {
        stack<int>st;
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++) {
            if(st.size() == 0) {
                ans.push_back(-1);
            }
            else if(st.size() > 0 && st.top() > nums[i]) {
                ans.push_back(st.top());
            }
            else if(st.size() > 0 && st.top() <= nums[i]) {
                while(st.size() > 0 && st.top() <= nums[i]) {
                    st.pop();
                }
                st.size() == 0 ? ans.push_back(-1) : ans.push_back(st.top());
            }
            st.push(nums[i]);
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
    vector<int>arr = {5,3,2,4};
    vector<int>ans = p->nextLargestElementLeft(arr);
    for(int i =0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
*/