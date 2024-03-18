class Solution {
public:
    int xMoves[4] = {0,1,0,-1};
    int yMoves[4] = {1,0,-1,0};
    bool helpExist(vector<vector<char>>& board,string word,int x,int y) {
        if(!word.size()) {
            return true;
        }
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[0]) {
            return false;
        }
        char temp = board[x][y];
        board[x][y]='*';
        for(int i = 0; i < 4; i++) {
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
            if(helpExist(board,word.substr(1),nextX,nextY)) {
                return true;
            }
        }
        board[x][y] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board,string& word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(helpExist(board,word,i,j)) {
                       return true;
                    }
                }
            }
        }
        return false;   
    }
};

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
//----------------------------------------------------------------------------------------------------------------///
class Solution {
public:
	bool adjSearch(int ind,int i,int j,string &word,vector<vector<char>>&board) {
		int m=board.size()-1;
		int n=board[0].size()-1;
		if(ind==word.size()) {
			return true;
		}
		if(i<0 || j<0 || i>m || j>n) {
			return false;
		}
		if(board[i][j]!=word[ind]) {
			return false;
		}
		board[i][j]='*';
		bool pathSearch=adjSearch(ind+1,i+1,j,word,board) || 
						adjSearch(ind+1,i-1,j,word,board) ||
						adjSearch(ind+1,i,j-1,word,board) ||
						adjSearch(ind+1,i,j+1,word,board);
		board[i][j]=word[ind];
		return pathSearch;
	}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++) {
        	for(int j=0;j<board[0].size();j++) {
        		if(adjSearch(0,i,j,word,board)) {
        			return true;
        		}
        	}
        }
        return false;
    }
};
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p=new Solution();
	vector<vector<char>>board{ {'A','B','C','E'},
							   {'S','F','C','S'},
							   {'A','D','E','E'},
							  };
	string word="ABCCED";
	cout<<p->exist(board,word);
    return 0;
}
*/
