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
	vector<int> topKFrequentElement(vector<int>&nums,int k) {
		vector<int>ans;
		unordered_map<int,int>m;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
		for(int i = 0; i< nums.size(); i++) {
			m[nums[i]]++;
		}
		for(auto it = m.begin(); it != m.end(); it++) {
			pq.push({it->second,it->first});
			if(pq.size() > k) {
				pq.pop();
			}
		}
		while(pq.size() > 0) {
			ans.push_back(pq.top().second);
			pq.pop();
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
	Solution *p = new Solution();
	vector<int>arr = {1,1};
	int k = 1; 
    vector<int>ans = p->topKFrequentElement(arr,k);
    for(int i = 0; i < ans.size(); i++) {
    	cout<<ans[i]<<" ";
    }
    return 0;
}
