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
    int occureneOfAnagram(string pat, string txt) {
        unordered_map<char,int>m;        
        for(auto i:pat) {
            m[i]++;
        }
        int k=pat.size();
        int cnt=m.size();
        int ans=0;
        int i=0,j=0;
        while(j<txt.size()) {
            if(m.find(txt[j])!=m.end()) {
                m[txt[j]]--;
                if(m[txt[j]]==0) {
                    cnt--;
                }
            }
            if(j-i+1<k) {
                j++;
            }
            else if(j-i+1==k) {
                if(cnt==0) {
                    ans++;
                }
                if(m.find(txt[i])!=m.end()) {
                    m[txt[i]]++;
                    if(m[txt[i]]==1) {
                        cnt++;
                    }
                }
                i++,j++;
            }
        }
        return ans;        
    }
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution *p=new Solution();
    string pat="for",txt="forxxorfxdofr"; //Ans:-3
    cout<<p->occureneOfAnagram(pat,txt);
    return 0;

}
