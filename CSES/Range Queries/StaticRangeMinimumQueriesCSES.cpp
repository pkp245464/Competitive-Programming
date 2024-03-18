/*Problem Link - "https://cses.fi/problemset/task/1647"*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
void build(int ind,int low,int high,vector<int>&arr,vector<int>&seg) {
    if(low == high) {
        seg[ind] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * ind + 1,low,mid,arr,seg);
    build(2 * ind + 2,mid + 1,high,arr,seg);
    seg[ind] = min(seg[2 * ind + 1],seg[2 * ind + 2]);
}
int query(int ind,int low,int high,int l,int r,vector<int>&seg) {
    if(r < low || high < l) {
        return INT_MAX;
    }
    if(low >= l && high <= r) {
        return seg[ind];
    }
    int mid = low + (high - low) / 2;
    int left = query(2 * ind + 1,low,mid,l,r,seg);
    int right = query(2 * ind + 2,mid + 1,high,l,r,seg);
    return min(left,right);
}
int main() {
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,q;
    cin >> n >> q;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int>seg(4 * n + 1);
    build(0,0,n - 1,arr,seg);
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout<<query(0,0,n - 1,l - 1,r - 1,seg)<<nl;
    }
    return 0;
}