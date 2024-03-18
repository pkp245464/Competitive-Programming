//https://atcoder.jp/contests/abc309/tasks/abc309_b


//Time Complexity : O(n^2)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<ll>>a(n,vector<ll>(n)),b;
    b = a;
    for(ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(ll j = 0; j < n; j++) {
            if(s[j] == '0') {
                a[i][j] = 0;
            }
            else {
                a[i][j] = 1;
            }
        }    
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                if(i == 0 && j < n - 1) {
                    b[i][j + 1] = a[i][j];
                }
                if(i < n - 1 && j == n - 1) {
                    b[i + 1][j] = a[i][j];
                }
                if(i == n - 1 && j > 0) {
                    b[i][j - 1] = a[i][j];
                }
                if(i > 0 && j == 0) {
                    b[i - 1][j] = a[i][j];
                }
            }
            else {
                b[i][j] = a[i][j];
            }
        }
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cout << b[i][j];
        }
        cout << nl;
    }
    return 0;
}


//Or
/*
Time Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<string>a(n),b;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    b = a;
    for(ll j = 1; j < n; j++) {
        b[0][j] = a[0][j - 1];
    }
    for(ll i = 1; i < n; i++) {
        b[i][n - 1] = a[i - 1][n - 1];
    }
    for(ll j = 0; j < (n - 1); j++) {
        b[n - 1][j] = a[n - 1][j + 1];
    }
    for(ll i = 0; i < (n - 1); i++) {
        b[i][0] = a[i + 1][0];
    }
    for(ll i = 0; i < n; i++) {
        cout << b[i] << nl;
    }
    return 0;
}
*/
