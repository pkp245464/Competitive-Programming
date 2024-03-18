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
    int longestValidParentheses(string s) {
        int maxi = 0;
        stack<int>st;
        st.push(-1);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                else {
                    maxi = max(maxi,i - st.top());
                }
            }
        }
        return maxi;        
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    string s = ")()())";
    cout<<p->longestValidParentheses(s)<<nl;
    return 0;
}
