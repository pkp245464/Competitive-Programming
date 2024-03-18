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
    bool isSafe(int i,int j,vector<vector<int>>&matrix) {
        if(i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && matrix[i][j] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    int rottenOranges(vector<vector<int>>&matrix) {
        int cnt = 2;
        bool flag = false;
        int row = matrix.size();
        int col = matrix[0].size();
        while(true) {
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    if(matrix[i][j] == cnt) {
                        if(isSafe(i + 1,j,matrix)) {
                            matrix[i + 1][j] = matrix[i][j] + 1;
                            flag = true;
                        }
                        if(isSafe(i,j + 1,matrix)) {
                            matrix[i][j + 1] = matrix[i][j] + 1;
                            flag = true;
                        }
                        if(isSafe(i - 1,j,matrix)) {
                            matrix[i - 1][j] = matrix[i][j] + 1;
                            flag = true;
                        }
                        if(isSafe(i,j - 1,matrix)) {
                            matrix[i][j - 1] = matrix[i][j] + 1;
                            flag = true;
                        }
                    }
                }
            }
            if(flag == false) {
                break;
            }
            flag = false;
            cnt++;
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 1) {
                    return -1;
                }
            }
        }
        return cnt - 2;
    }
};
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p = new Solution();
    vector<vector<int>>arr = { {2,1,0,2,1},
                               {1,0,1,2,1},
                               {1,0,0,2,1} };
    cout<<p->rottenOranges(arr);
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
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
    bool isValid(int i,int j,vector<vector<int>>&grid) {
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0,fresh = 0;
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>>q;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if(fresh == 0) {
            return 0;
        }
        while(!q.empty()) {
            int sizeQ = q.size();
            int temp = 0;
            while(sizeQ--) {
                pair<int,int>pos = q.front();
                q.pop();
                int posX = pos.first;
                int posY = pos.second;
                vector<int>dirX = {1,-1,0,0};
                vector<int>dirY = {0,0,1,-1};
                for(int i = 0; i < 4; i++) {
                    int x = dirX[i] + posX;
                    int y = dirY[i] + posY;
                    if(isValid(x,y,grid)) {
                        temp++;
                        q.push({x,y});
                        grid[x][y] = 2;
                    }
                }
            }
            if(temp != 0) {
                time++;
            }
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p = new Solution();
    vector<vector<int>>arr = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<p->orangesRotting(arr)<<nl;
    return 0;
}
*/
