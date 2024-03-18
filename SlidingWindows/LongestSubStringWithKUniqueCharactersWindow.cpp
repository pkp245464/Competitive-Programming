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
    int longestSubStringKUnique(string s,int k) {
        unordered_map<char,int>m;
        int maxi=INT_MIN;
        int i=0,j=0;
        while(j<s.size()) {
            m[s[j]]++;
            if(m.size()==k) {
                maxi=max(maxi,j-i+1);
            }
            else if(m.size() > k) {
                while(m.size() > k) {
                    m[s[i]]--;
                    if(m[s[i]]==0) {
                        m.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution *p=new Solution();
    string s="aabacbebebe";
    int k=3;
    cout<<p->longestSubStringKUnique(s,k);
    return 0;

}
