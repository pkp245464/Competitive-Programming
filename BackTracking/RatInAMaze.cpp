#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
    void fun(int i,int j,int n,string move,vector<string>&ans,vector<vector<int>>&vis,vector<vector<int>>&maze) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        //Downwards
        if(i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1) {
            vis[i][j] = 1;
            fun(i + 1,j,n,move + 'D',ans,vis,maze);
            vis[i][j] = 0;
        }
        //Leftwards
        if(j - 1 >= 0 && !vis[i][j - 1] && maze[i][j - 1] == 1) {
            vis[i][j] = 1;
            fun(i,j - 1,n,move + 'L',ans,vis,maze);
            vis[i][j] = 0;
        }
        //Rigthwards
        if(j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1) {
            vis[i][j] = 1;
            fun(i,j + 1,n,move + 'R',ans,vis,maze);
            vis[i][j] = 0;
        }
        //Upwards
        if(i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1) {
            vis[i][j] = 1;
            fun(i - 1,j,n,move + 'U',ans,vis,maze);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>>&maze) {
        string move;
        vector<string>ans;
        int i = 0,j = 0,n = maze.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(maze[0][0] == 1) {
            fun(i,j,n,move,ans,vis,maze);
        }
        return ans;
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    vector<vector<int>>arr = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string>ans = p->findPath(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<nl;
    }
    return 0;
}

//Or

/*
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
    string dir = "DLRU";
    vector<int>dirX = {1,0,0,-1};
    vector<int>dirY = {0,-1,1,0};
    void fun(int i,int j,int n,string move,vector<string>&ans,vector<vector<int>>&vis,vector<vector<int>>&maze) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        for(int ind = 0; ind < 4; ind++) {
            int posX = i + dirX[ind];
            int posY = j + dirY[ind];
            if(posX >= 0 && posX < n && posY >= 0 && posY < n && !vis[posX][posY] && maze[posX][posY] == 1) {
                vis[i][j] = 1;
                fun(posX,posY,n,move + dir[ind],ans,vis,maze);
                vis[i][j] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>>&maze) {
        string move;
        vector<string>ans;
        int i = 0,j = 0,n = maze.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(maze[0][0] == 1) {
            fun(i,j,n,move,ans,vis,maze);
        }
        return ans;
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    vector<vector<int>>arr = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string>ans = p->findPath(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<nl;
    }
    return 0;
}
*/