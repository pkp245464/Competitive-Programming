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
	vector<int> kClosestElement(vector<int>&nums,int k,int x) {
		vector<int>ans;
		priority_queue<pair<int,int>>pq;
		for(int i = 0; i < nums.size(); i++) {
			pq.push({abs(nums[i]-x),nums[i]});
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
	vector<int>arr = {1,2,3,4,5};
	int k = 4,x = 3; 
    vector<int>ans = p->kClosestElement(arr,k,x);
    for(int i = 0; i < ans.size(); i++) {
    	cout<<ans[i]<<" ";
    }
    return 0;
}
