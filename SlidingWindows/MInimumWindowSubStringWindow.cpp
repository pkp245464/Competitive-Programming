//Print The Length Of String
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------/// 
class Solution  { 
public:
    int minWindowSubString(string s,string t) {
        unordered_map<char,int>m;
        for(int i=0 ;i<t.size();i++) {
            m[t[i]]++;
        }
        int ans=INT_MAX;
        int cnt=m.size();
        int i=0,j=0;
        while(j<s.length()) {
            if(m.find(s[j])!=m.end()) {
                 m[s[j]]--;
                if(m[s[j]]==0) {
                    cnt--;
                }
            }
            if(cnt==0) {
                ans=min(ans,j-i+1); 
                while(cnt==0) {
                    if(m.find(s[i])==m.end()) {
                        i++;
                        ans=min(ans,j-i+1);   
                    }
                    else {
                        m[s[i]]++;
                        if(m[s[i]]>0) {
                            i++;
                            cnt++;
                        }
                        else {
                            i++;
                            ans=min(ans,j-i+1); 
                        }
                    }
                }
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
	Solution *p=new Solution;
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<p->minWindowSubString(s,t);
    return 0;

}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Print The String

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
    string minWindow(string s, string t) {
        string ans = "";
        if(s.size() < t.size()) {
            return ans;
        }
        unordered_map<char,int>m;
        int i = 0,j = 0,cnt = 0,mini = INT_MAX;
        for(int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        cnt = m.size();
        while(j < s.size()) {
            if(m.find(s[j]) != m.end()) {
                m[s[j]]--;
                if(m[s[j]] == 0) {
                    cnt--;
                }
            }
            if(cnt == 0) {
                if(mini > j - i + 1) {
                    mini = j - i + 1;
                    ans = s.substr(i,mini);
                }    
                while(i <= j && cnt == 0) {
                    if(m.find(s[i]) != m.end()) {
                        m[s[i]]++;
                        if(m[s[i]] == 1) {
                            if(mini > j - i + 1) {
                                mini = j - i + 1;
                                ans = s.substr(i,mini);
                            }    
                            cnt++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(mini == INT_MAX) {
            return "";
        }
        else {
            return ans;
        }
    }
};
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p = new Solution();
    string s = "ADOBECODEBANC",t = "ABC";
    cout<<p->minWindow(s,t)<<nl;
    return 0;
}
*/