#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
class Solution {
public:  
	void generateSolve(int open,int close,string s,vector<string>&ans) {
		if(open==0 && close==0) {
			ans.push_back(s);
			return; 
		}
		if(open>0) {
			generateSolve(open-1,close,s+'(',ans);
		}
		if(close>open) {
			generateSolve(open,close-1,s+')',ans);	
			return;
		}
	}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        int open=n;
        int close=n;
        generateSolve(open,close,s,ans);
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
	int n=3;
	vector<string>ans=p->generateParenthesis(n);
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<nl;
	}
    return 0;
}
