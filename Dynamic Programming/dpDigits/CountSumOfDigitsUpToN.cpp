/*
A positive integer n is called a good integer when n is divisible by its digit sum.You are given a positive integer 
N. How many good integers are less than or equal to N ?*/

//https://atcoder.jp/contests/abc336/tasks/abc336_e
*/

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll N;
    cin >> N;
    N += 1;
    string s = to_string(N);
    ll ans = 0;
    int sz = (int)s.size();   
    for(int i = 1; i <= 9 * sz; i++) {
		//ll dp[sz + 1][2][i + 1][i];
        //memset(dp,0,sizeof(dp));
		vector<vector<vector<vector<ll>>>>dp(sz + 1,vector<vector<vector<ll>>>(2,vector<vector<ll>>(i + 1,vector<ll>(i,0))));
        dp[0][0][0][0] = 1;
        for(int j = 0; j < sz; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l <= i; l++) {
                    for(int m = 0; m < i; m++) {
                        for(int n = 0; n <= 9; n++) {
                            if(!(k == 0 && n > (s[j] - '0')) && (l + n) <= i) {
                                int k2 = k | (n < s[j] - '0');
                                int l2 = l + n;
                                int m2 = (m * 10 + n) % i;
                                dp[j + 1][k2][l2][m2] += dp[j][k][l][m];
                            }
                        }
                    }
                }
            }
        }
        ans += dp[sz][1][i][0];
    }
    cout << ans << nl;
    return 0;
}