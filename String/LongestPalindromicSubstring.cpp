#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
string longestPalindromicSubstring(string &s) {
    string ans = "";
    int n = s.size(),maxLen = 0;
    vector<vector<int>>dp(n + 2,vector<int>(n + 2,0));
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
        if(maxLen < dp[i][i]) {
            maxLen = dp[i][i];
            ans = s.substr(i,1);
        }    
    } 
    for(int window = 2; window <= n; window++){  
        for(int i = 0; i < (n - window + 1); i++){
            int j = i + window - 1;
            if(window == 2 && s[i] == s[j]){
                dp[i][j] = 2;
                if(maxLen < dp[i][j]){
                    maxLen = dp[i][j];
                    ans = s.substr(i,2);
                  }
            }
            else if (s[i] == s[j] and dp[i + 1][j - 1] > 0){
                dp[i][j] = window;
                if(maxLen < dp[i][j]){
                        maxLen = dp[i][j];
                        ans = s.substr(i,window);
                   }  
            }
            else dp[i][j] = 0;
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
    string s = "aacabdkacaa";
    cout << longestPalindromicSubstring(s) << nl;
    return 0;
}