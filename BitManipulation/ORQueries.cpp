#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int N = 5e5 + 10;
vector<vector<int>>pre(32,vector<int>(N));
void cal(vector<int>&a) {
    int n = a.size();
    for(int i = 0; i < 32; i++) {
        pre[i][0] = ((a[0] >> i) & 1);
        for(int j = 1; j < n; j++) {
            pre[i][j] = ((a[j] >> i) & 1);
            pre[i][j] += pre[i][j - 1];
        }
    }
}
int rangeOr(int l,int r) {
    int ans = 0; 
    for(int i = 0; i < 32; i++) {
        int x;
        if(l == 0) {
            x = pre[i][r];
        }
        else {
            x = pre[i][r] - pre[i][l - 1];
        } 
        if(x != 0) {
            ans = (ans | (1 << i));
        }
    }
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cal(a); 
    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << rangeOr(l,r) << nl;
    }
    return 0;
}