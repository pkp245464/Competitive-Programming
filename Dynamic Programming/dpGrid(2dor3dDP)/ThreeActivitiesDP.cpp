//https://codeforces.com/contest/1914/problem/D

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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>a(n),b(n),c(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        multiset<pair<int,int>>x,y;
        for(int i = 0; i < n; i++) {
            x.insert({b[i],i});
            y.insert({c[i],i});
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
			//deleting index 'a' & 'b' because we are selecting index array 'a' and in question every index should be distinct
            x.erase({b[i],i});
            y.erase({c[i],i});
            if((*x.rbegin()).second == (*y.rbegin()).second) { //maximum element equal both at same index in array 'b' & 'c'
                int p = a[i] + (*(--x.end())).first + (*(--(--y.end()))).first; //select max from array 'b' && select second max from array 'c'
                int q = a[i] + (*(--(--x.end()))).first + (*(--y.end())).first; //select max from array 'c' && select second max from array 'b'
                ans = max({ans,p,q});
            }
            else {
				//select max element from both array 'a' & 'b'
                ans = max(ans,a[i] + (*(--x.end())).first + (*(--y.end())).first);
            }
            x.insert({b[i],i});
            y.insert({c[i],i});
        }
        cout << ans << nl;
    }    
    return 0;
}

//second method
/*
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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>>a(n,vector<int>(3));
        for(int i = 0; i < n; i++) {
            cin >> a[i][0];
        }
        for(int i = 0; i < n; i++) {
            cin >> a[i][1];
        }
        for(int i = 0; i < n; i++) {
            cin >> a[i][2];
        }
        vector<vector<int>>dp(n + 1,vector<int>(8));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 8; j++) {
                for(int k = 0; k < 3; k++) {
                    dp[i + 1][j] = max(dp[i + 1][j],dp[i][j]);
                    if((j & (1 << k)) == 0) {
                        dp[i + 1][j | (1 << k)] = max(dp[i + 1][j | (1 << k)],dp[i][j] + a[i][k]);
                    }
                }
            }
        }
        cout << dp[n][7] << nl;
    }    
    return 0;
}
*/

/*
I/P:
4
3
1 10 1
10 1 1
1 1 10
4
30 20 10 1
30 5 15 20
30 25 10 10
10
5 19 12 3 18 18 6 17 10 13
15 17 19 11 16 3 11 17 17 17
1 17 18 10 15 8 17 3 13 12
10
17 5 4 18 12 4 11 2 16 16
8 4 14 19 3 12 6 7 5 16
3 4 8 11 10 8 10 2 20 3
O/P:
30
75
55
56
*/