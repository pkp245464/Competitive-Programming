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
	int kthLargestElement(vector<int>&nums,int k) {
		//Using Min Heap
		priority_queue<int,vector<int>,greater<int>>pq;  
		for(int i = 0; i < nums.size(); i++) {
			pq.push(nums[i]);
			if(pq.size() > k) {
				pq.pop();
			}
		}
		return pq.top();
	}
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution *p = new Solution();
	vector<int>arr{7,10,4,3,20,15};
	//20,15,10,7,4,3
	int k = 1;
    cout<<p->kthLargestElement(arr,k);
    return 0;
}

