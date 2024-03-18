//Sudoku Solver 
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
    bool isSafe(vector<vector<char>>&board,int row,int col,char c) {
        for(int i=0;i<board.size();i++) {
            if(board[i][col]==c) {
                return false;
            }
            if(board[row][i]==c) {
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) {
                return false;
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]=='.') {
                    for(char c='1';c<='9';c++) {
                        if(isSafe(board,i,j,c)) {
                            board[i][j]=c;
                            if(solveSudoku(board)) {
                                return true;
                            }
                            else {
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p=new Solution();
    vector<vector<char>>board
    { 
        {'1','.','.',    '8','9','4',     '.','.','2'},
        {'.','.','2',    '.','.','.',     '3','.','.'},
        {'7','.','.',    '3','.','6',     '.','.','5'},
                                                          
        {'.','3','.',    '2','.','5',     '.','4','.'},
        {'.','.','4',    '.','.','.',     '8','.','.'},
        {'.','8','.',    '6','.','1',     '.','7','.'},
                                                            
        {'3','.','.',    '5','.','2',     '.','.','4'},
        {'.','.','6',    '.','.','.',     '1','.','.'},
        {'8','.','.',    '9','6','3',     '.','.','7'} 
    };
    p->solveSudoku(board);
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<nl;
    }
    return 0;
}
//--------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------//
//Check Sudoku is Valid or not
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
    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<set<int>>row(m),col(m),block(m);
        for(int i=0;i<m;i++) {
        	for(int j=0;j<n;j++) {
        		if(board[i][j]=='.') {
        			continue;
        		}
        		int curr=board[i][j];
        		if(row[i].count(curr) || col[j].count(curr) || 
        			block[(i/3)*3+j/3].count(curr)) {
        			return false;
        		}
        		row[i].insert(curr);
        		col[j].insert(curr);
        		block[(i/3*3)+j/3].insert(curr);
        	}
        }
        return true;
    }
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p=new Solution();
	vector<vector<char>>board
	{ 
		{'.','8','7','6','5','4','3','2','1'},
		{'2','.','.','.','.','.','.','.','.'},
		{'3','.','.','.','.','.','.','.','.'},
		{'4','.','.','.','.','.','.','.','.'},
		{'5','.','.','.','.','.','.','.','.'},
		{'6','.','.','.','.','.','.','.','.'},
		{'7','.','.','.','.','.','.','.','.'},
		{'8','.','.','.','.','.','.','.','.'},
		{'9','.','.','.','.','.','.','.','.'} 
	};
	cout<<p->isValidSudoku(board);	
    return 0;
}
*/