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
	void solve(string digits,string s,vector<string>&ans) {
		vector<string>vs={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wzyz"};
		if(digits.size()==0) {
			ans.push_back(s);
			return;
		} 
		string str=vs[digits[0]-'0'];
		digits.erase(digits.begin()+0);
		for(int i=0;i<str.size();i++) {
			solve(digits,s+str[i],ans);
		}
	}
    vector<string> letterCombinations(string digits) {
        if(digits=="") {
        	return {};
        }
        string s="";
        vector<string>ans;
        solve(digits,s,ans);
        return ans;
    }
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p=new Solution();
	string s="9";
	vector<string>ans=p->letterCombinations(s);
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<" ";
	}
    return 0;
}
