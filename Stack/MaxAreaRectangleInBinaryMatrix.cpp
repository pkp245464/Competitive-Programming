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
	int maxAreaInHistogram(vector<int>&nums) {
		int n = nums.size();
		
		vector<int>left;
		stack<pair<int,int>>s1;   
		int indleft = -1;
		for(int i = 0; i < n; i++) {
			if(s1.size() == 0) {
				left.push_back(indleft);
			}
			else if(s1.size() > 0 && s1.top().first < nums[i]) {
				left.push_back(s1.top().second);
			}
			else if(s1.size() > 0 && s1.top().first >= nums[i]) {
				while(s1.size() > 0 && s1.top().first >= nums[i]) {
					s1.pop();
				}
				if(s1.size() == 0) {
					left.push_back(indleft);
				}
				else {
					left.push_back(s1.top().second);
				}
			}
			s1.push({nums[i],i});
		}

		vector<int>right;
		stack<pair<int,int>>s2;
		int indright = n;
		for(int  i = n-1; i >= 0; i--) {
			if(s2.size() == 0) {
				right.push_back(indright);
			}
			else if(s2.size() > 0 && s2.top().first < nums[i]) {
				right.push_back(s2.top().second);
			}
			else if(s2.size() > 0 && s2.top().first >= nums[i]) {
				while(s2.size() > 0 && s2.top().first >= nums[i]) {
					s2.pop();
				}
				if(s2.size() == 0) {
					right.push_back(indright);
				}
				else {
					right.push_back(s2.top().second);
				}
			}
			s2.push({nums[i],i});
		}
		reverse(right.begin(),right.end());

		int maxi = INT_MIN;
		for(int i = 0; i < n; i++) {
			maxi = max(maxi ,(right[i]-left[i]-1)*nums[i]);
		}
		return maxi;
	}
	int maxAreaInBinaryMatrixRectangle(vector<vector<int>>&matrix) {
		int m = matrix.size();
		if(m == 0) return 0;
		int n = matrix[0].size();
		int ans = 0;
		vector<int>nums(n,0);
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(matrix[i][j] == 1) {
					nums[j] = nums[j] + matrix[i][j];
				}
				else if(matrix[i][j] == 0) {
					nums[j] = 0;
				}
			}
			ans = max(ans,maxAreaInHistogram(nums));
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
	vector<vector<int>>arr{ {0,1,1,0},
							{1,1,1,1},
							{1,1,1,1},
							{1,1,0,0} };
	cout<<p->maxAreaInBinaryMatrixRectangle(arr); 
    return 0;
}
