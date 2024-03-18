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
	static bool comparator(pair<int,int>a,pair<int,int>b) {
		if(a.second == b.second) {
			return a.first > b.first;
		}
		else return (a.second < b.second);
	}
    vector<int> frequencySort(vector<int>& nums) {
    	unordered_map<int,int>m;
    	vector<pair<int,int>>p;
    	for(int i = 0; i < nums.size(); i++) {
    		m[nums[i]]++;
    	}
    	nums.clear();
    	for(auto it = m.begin(); it !=m.end(); it++) {
    		p.push_back({it->first,it->second});
    	}
    	sort(p.begin(),p.end(),comparator);
    	for(int i = 0; i < p.size(); i ++) {
    		for(int j = 0; j < p[i].second; j++) {
    			nums.push_back(p[i].first);
    		}
    	}
    	return nums;
    }
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p = new Solution();
	vector<int>arr = {1,5,0,5};
	vector<int>ans = p->frequencySort(arr);
	for(int i = 0; i < ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
    return 0;
}
