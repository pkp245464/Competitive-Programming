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
    bool isValid(int i,int j,int n,vector<vector<bool>>&vis) {
        if(i >= 0 && i < n && j >= 0 && j < n && vis[i][j] == false) {
            return true;
        }
        return false;
    }
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n) {
        int starPosX = KnightPos[0] - 1,startPosY = KnightPos[1] - 1;
        int targetPosX = TargetPos[0] - 1,targetPosY = TargetPos[1] - 1;
        if(starPosX == targetPosX && startPosY == targetPosY) {
            return 0;
        }  
        int ans = 0;
        queue<pair<int,int>>q;
        q.push({starPosX,startPosY});
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[starPosX][startPosY] = true;
        while(!q.empty()) {
            int sizeQ = q.size();
            ans++;
            while(sizeQ--) {
                pair<int,int>temp = q.front();
                q.pop();
                int curPosX = temp.first;
                int curPosY = temp.second;
                vector<int>dirX = {2,1,-2,-1,-2,-1,2,1};
                vector<int>dirY = {1,2,1,2,-1,-2,-1,-2};
                for(int i = 0; i < 8; i++) {
                    int x = curPosX + dirX[i];
                    int y = curPosY + dirY[i];
                    if(x == targetPosX && y == targetPosY) {
                        return ans;
                    }
                    if(isValid(x,y,n,vis)) {
                        vis[x][y] = true;
                        q.push({x,y});
                    }
                }
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
    Solution *p = new Solution();
    int n = 6;
    vector<int>KnightPos = {4,5};
    vector<int>TargetPos = {1,1};
    cout<<p->minStepToReachTarget(KnightPos,TargetPos,n)<<nl;
    return 0;
}