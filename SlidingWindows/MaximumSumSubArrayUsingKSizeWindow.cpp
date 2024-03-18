#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define phb push_back
#define phf push_front
#define ppf pop_front
#define ppb pop_back
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
	void maximumSubArray(int k,vector<int>&nums) {
		int i=0,j=0,sum=0;
		int n=nums.size();
		int maxi=INT_MIN;
		while(j<n) {
			sum=sum+nums[j];
			if(j-i+1<k) {
				j++;
			}
			else if((j-i+1)==k) {
				maxi=max(maxi,sum);
				sum=sum-nums[i];
				i++,j++;
			}
		}
		cout<<"Maximum SubArray: "<<maxi<<nl;
	}
};
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p=new Solution();
	vector<int>nums{5,1,7,2,9,4,6,3,8};
	int k=3;
	p->maximumSubArray(k,nums);
	return 0;
}

