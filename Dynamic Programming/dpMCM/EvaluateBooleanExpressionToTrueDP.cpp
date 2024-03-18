//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int MOD = 1e3 + 3;
int fun(int i,int j,bool istrue,string &s){
	if(i > j) {
		return 0;
	}
	if(i == j){
		if(istrue) {
			return s[i] == 'T';
		}
		else return s[i] == 'F';
	}
	int ways = 0;
	for(int k = i + 1; k <= j - 1; k += 2) {
		if(s[k] != 'T' && s[k] != 'F') {
		int leftTrue = fun(i,k - 1,1,s);
		int leftFalse = fun(i,k - 1,0,s);
		int rightTrue = fun(k + 1,j,1,s);
		int rightFalse = fun(k + 1,j,0,s);
		
		if(s[k] == '&') {
			if(istrue){
				ways = (ways + (rightTrue * leftTrue) % MOD) % MOD;
			}
			else {
				ways = (ways + (leftTrue * rightFalse) % MOD + (rightTrue * leftFalse) % MOD + 
					   (rightFalse * leftFalse) % MOD) % MOD;
			}
		}
		else if(s[k] == '|') {
			if(istrue){
				ways = (ways + (leftTrue * rightTrue) % MOD + (leftFalse * rightTrue) % MOD + 
					   (rightFalse * leftTrue) % MOD) % MOD;
			}
			else{
				ways = (ways + (leftFalse * rightFalse) % MOD) % MOD;
			}
		}
		else{
			if(istrue) {
				ways =(ways + (leftTrue * rightFalse) % MOD + (leftFalse * rightTrue) % MOD) % MOD;
			}
			else {
				ways = (ways + (leftTrue * rightTrue) % MOD + (leftFalse * rightFalse) % MOD) % MOD;
			}
		}
	  }
	}   
	return ways % MOD;
}
int cntWays(string &s) {
	int n = s.size();
	return fun(0,n - 1,1,s);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "T|T&F^T";
    cout << cntWays(s) << nl;                        
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Memoization Method

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
class Solution {
public:
    int MOD = 1003;
    int fun(int i,int j,bool istrue,string &s,vector<vector<vector<int>>>&dp){
        if(i > j){
            return 0;
        }
        if(i == j){
            if(istrue) {
                return s[i] == 'T';
            }
            else return s[i] == 'F';
        }
        if(dp[i][j][istrue] != -1){
            return dp[i][j][istrue];
        }
        int ways = 0;
        for(int k = i + 1; k <= j -1; k += 2) {
            if(s[k] != 'T' && s[k] != 'F') {
            int leftTrue = fun(i,k - 1,1,s,dp);
            int leftFalse = fun(i,k - 1,0,s,dp);
            int rightTrue = fun(k + 1,j,1,s,dp);
            int rightFalse = fun(k + 1,j,0,s,dp);
            
            if(s[k] == '&') {
                if(istrue){
                    ways = (ways + (rightTrue * leftTrue) % MOD) % MOD;
                }
                else {
                    ways = (ways + (leftTrue * rightFalse) % MOD + (rightTrue * leftFalse) % MOD + 
                           (rightFalse * leftFalse) % MOD) % MOD;
                }
            }
            else if(s[k] == '|') {
                if(istrue){
                    ways = (ways + (leftTrue * rightTrue) % MOD + (leftFalse * rightTrue) % MOD + 
                           (rightFalse * leftTrue) % MOD) % MOD;
                }
                else{
                    ways = (ways + (leftFalse * rightFalse) % MOD) % MOD;
                }
            }
            else{
                if(istrue) {
                    ways =(ways + (leftTrue * rightFalse) % MOD + (leftFalse * rightTrue) % MOD) % MOD;
                }
                else {
                    ways = (ways + (leftTrue * rightTrue) % MOD + (leftFalse * rightFalse) % MOD) % MOD;
                }
            }
          }
        }
            
        return dp[i][j][istrue] = ways % MOD;
    }
    int cntWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return fun(0,n - 1,1,s,dp);
    }
};
int main() {
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p = new Solution();
    string s = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    cout << p->cntWays(s) << nl;                        
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Tabulation Method

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
class Solution {
public:
    int MOD = 1003;
    int cntWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(i == j) {
                    dp[i][j][0] = (s[i] == 'F');
                    dp[i][j][1] = (s[i] == 'T');
                }
                else {
                    int ways = 0;
                    for(int ind = i + 1; ind <= j - 1; ind += 2) {
                        int leftTrue = dp[i][ind - 1][1] % MOD;
                        int rightTrue = dp[ind + 1][j][1] % MOD;
                        int leftFalse = dp[i][ind - 1][0] % MOD;
                        int rightFalse = dp[ind + 1][j][0] % MOD;
                        if(s[ind] == '&') {
                            dp[i][j][0] = (dp[i][j][0] + (leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse)) % MOD;
                            dp[i][j][1] = (dp[i][j][1] + (leftTrue * rightTrue)) % MOD;
                        }
                        else if(s[ind] == '|') {
                            dp[i][j][0] = (dp[i][j][0] + (leftFalse * rightFalse)) % MOD;
                            dp[i][j][1] = (dp[i][j][1] + (leftTrue * rightFalse + leftFalse * rightTrue + leftTrue * rightTrue)) % MOD;
                        }
                        else if(s[ind] == '^') {
                            dp[i][j][0] = (dp[i][j][0] + (leftTrue * rightTrue + leftFalse * rightFalse)) % MOD;
                            dp[i][j][1] = (dp[i][j][1] + (leftTrue * rightFalse + leftFalse * rightTrue)) % MOD;
                        }
                    }
                }
            }
        }
        return dp[0][n - 1][1];
    }
};
int main() {
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p = new Solution();
    string s = "F^F&T&F^T|T^F^T^F^T&F^F^T|F|T|F&F&F|F|T&F|F&F^T&F&F^T|T|T|T^T&T|T^F&T|T^F&T|T^F&T&F|T|T^T&F&T|T&F^F";
    cout << p->cntWays(s) << nl;                        
    return 0;
}
*/