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
	int kthSmallestElement(vector<int>&nums,int k) {
		priority_queue<int>pq;  //Using Max Heap
		for(int i = 0; i < nums.size(); i++) {
			pq.push(nums[i]);
			if(pq.size() > k) {
				pq.pop();
			}
		}
		return pq.top();
	}
	int sumBetweenK1SmallestK2Smallest(vector<int>&nums,int k1,int k2) {
		int sum = 0;
		int first = kthSmallestElement(nums,k1);
		int second = kthSmallestElement(nums,k2);
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] > first && nums[i] < second) {
				sum += nums[i];
			}
		}
		return sum;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p = new Solution();
	vector<int>arr{1,3,12,5,15,11};
	int k1 = 3, k2 = 6;
	cout<<p->sumBetweenK1SmallestK2Smallest(arr,k1,k2);
    return 0;
}
