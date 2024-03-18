#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
string decodeString(string s) {
    int n = s.size();
    stack<char>st;
    for(int i = 0; i < n; i++) {
        if(s[i] != ']') {
            st.push(s[i]);
        }
        else {
            string t="";
            while(!st.empty() && st.top() != '[') {
                t = st.top() + t;
                st.pop();
            }
            st.pop();
            string num = "";
            while(!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }
            int k = stoi(num);
            while(k--) {
                for(int j = 0; j < t.size(); j++)
                    st.push(t[j]);
            }
        }
    }
    string ans = "";
    while(!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;    
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "2[abc]3[cd]ef";
    cout << decodeString(s) << nl; //abcabccdcdcdef
    return 0;
}