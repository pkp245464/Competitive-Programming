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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i = 0; i < points.size(); i++) {
            pq.push({(points[i][0]*points[i][0])+(points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        while(pq.size() > 0) {
            pair<int,int>p = pq.top().second;
            ans.push_back({p.first,p.second});
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
    vector<vector<int>>arr = { {3,3},{5,-1},{-2,4} };
    int k = 2;
    vector<vector<int>>ans = p->kClosest(arr,k);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i][0]<<" "<<ans[i][1]<<nl;
    }
    return 0;
}
