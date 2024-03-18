//an array of n numbers.In how many ways can you choose a subset of the numbers with sum x?
//TC: O(N * 2 ^ (N / 2))
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
vector<ll> getSubSetSum(int l,int r,vector<int>&a) {
    int len = r - l + 1;
    vector<ll>ans;
    for(int i = 0; i < (1 << len); i++) {
        ll curSum = 0;
        for(int j = 0; j < len; j++) {
            if(i & (1 << j)) {
                curSum += a[l + j];
            }
        }
        ans.push_back(curSum);
    }
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,x;
    cin >> n >> x;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    vector<ll>left = getSubSetSum(0,n / 2 - 1,a);
    vector<ll>right = getSubSetSum(n / 2,n - 1,a);

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    ll cnt = 0;
    for(int i = 0; i < left.size(); i++) {
        ll lb = lower_bound(right.begin(),right.end(),x - left[i]) - right.begin();
        ll ub = upper_bound(right.begin(),right.end(),x - left[i]) - right.begin();
        cnt += (ub - lb); 
    }
    cout << cnt << nl;
    return 0;
}
/*
//https://cses.fi/problemset/task/1628/
I/P:
4 5
1 2 3 2
O/P: 3

for Practice:
https://codeforces.com/contest/888/problem/E
*/