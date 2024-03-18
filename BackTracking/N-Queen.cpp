//Using Backtracking
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
	bool isSafe(int row,int col,int n,vector<string>&board) {
		int duprow=row;
		int dupcol=col;
		while(row>=0 && col>=0) {
			if(board[row][col]=='Q') {
				return false;
			}
			row--;
			col--;
		}
		row=duprow;
		col=dupcol;
		while(col>=0) {
			if(board[row][col]=='Q') {
				return false;
			}
			col--;
		}
		row=duprow;
		col=dupcol;
		while(row<n && col>=0) {
			if(board[row][col]=='Q') {
				return false;
			}
			row++;
			col--;
		}
		return true;
	}
	void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans) {
		if(col==n) {
			ans.push_back(board);
			return;
		}
		for(int row=0;row<n;row++) {
			if(isSafe(row,col,n,board)) {
				board[row][col]='Q';
				solve(col+1,n,board,ans);
				board[row][col]='.';
			}
		}
	}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) {
        	board[i]=s;
        }
        solve(0,n,board,ans);
        return ans;
    }
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p=new Solution();
	int n=4;
	vector<vector<string>>ans=p->solveNQueens(n);
	for(int i=0;i<ans.size();i++) {
		cout<<"Arrangement: "<<i+1<<nl;
		for(int j=0;j<ans[0].size();j++) {
			cout<<ans[i][j]<<nl;
		}
		cout<<nl;
	}
    return 0;
}
//Second Method Using Hashing
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
	void solve(int col,int n,vector<int>&leftrow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,
		vector<string>&board,vector<vector<string>>&ans) {
		if(col==n) {
			ans.push_back(board);
			return;
		}
		for(int row=0;row<n;row++) {
			if(leftrow[row]==0 && upperDiagonal[n-1+col-row]==0 && lowerDiagonal[row+col]==0) {
				board[row][col]='Q';
				leftrow[row]=1;
				lowerDiagonal[row+col]=1;
				upperDiagonal[n-1+col-row]=1;
				solve(col+1,n,leftrow,upperDiagonal,lowerDiagonal,board,ans);
				board[row][col]='.';
				leftrow[row]=0;
				lowerDiagonal[row+col]=0;
				upperDiagonal[n-1+col-row]=0;
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) {
        	board[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>upperDiagonal(2*n-1,0);
        vector<int>lowerDiagonal(2*n-1,0);
        solve(0,n,leftrow,upperDiagonal,lowerDiagonal,board,ans);
        return ans;
    }
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p=new Solution();
	int n=4;
	vector<vector<string>>ans=p->solveNQueens(n);
	for(int i=0;i<ans.size();i++) {
		cout<<"Arrangement: "<<i+1<<nl;
		for(int j=0;j<ans[0].size();j++) {
			cout<<ans[i][j]<<nl;
		}
		cout<<nl;
	}
    return 0;
}
*/