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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        for(int i = 0; i < matrix.size(); i++) {
        	for(int j = 0; j < matrix.size(); j++) {
        		pq.push(matrix[i][j]);
        		if(pq.size() > k) {
        			pq.pop();
        		}
        	}
        }
        return pq.top();
    }
};
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p = new Solution();
	vector<vector<int>>arr = { {1,5,9},
							   {10,11,13},
							   {12,13,15} };
	int k = 8;
	cout<<p->kthSmallest(arr,k)<<nl;
    return 0;
}