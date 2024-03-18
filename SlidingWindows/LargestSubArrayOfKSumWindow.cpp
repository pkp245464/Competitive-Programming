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
    int largestSubArrayKSum(vector<int>&nums,int k) {
    	int sum=0;
    	int maxi=0;
    	int i=0,j=0;
    	while(j<nums.size()) {
    		sum+=nums[j];
    		if(sum>k) {
    			while(sum>k) {
    				sum=sum-nums[i++];
    			}
    		}
    		if(sum==k) {
    			maxi=max(maxi,j-i+1);
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
    vector<int>arr{1,2,1,2,1};
    int k=4;
    cout<<p->largestSubArrayKSum(arr,k);
    return 0;
}
