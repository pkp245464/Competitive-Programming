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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	vector<int>ans;
    	list<int>ls;
    	int i=0,j=0;
    	while(j<nums.size()) {
    		while(ls.size()>0 && ls.back()<nums[j]) {
    			ls.pop_back();
    		}
    		ls.push_back(nums[j]);
    		if(j-i+1<k) {
    			j++;
    		}
    		else if(j-i+1==k) {
    			ans.push_back(ls.front());
    			if(ls.front()==nums[i]) {
    				ls.pop_front();
    			}
    			i++,j++;
    		}
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
	Solution *p=new Solution();
	vector<int>arr{1,3,-1,-3,5,3,6,7}; //Ans:-3 3 5 5 6 7 
	int k=3;
	vector<int>ans=p->maxSlidingWindow(arr,k);	
    for(int i=0;i<ans.size();i++) {
    	cout<<ans[i]<<" ";
    }
    return 0;
}
