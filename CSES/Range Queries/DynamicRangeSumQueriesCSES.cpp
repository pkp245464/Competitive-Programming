/*Problem Link - "https://cses.fi/problemset/task/1648"*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
vector<ll>arr,seg;
ll buildTree(ll ind,ll low,ll high) {
    if(low == high) {
        return seg[ind] = arr[low];
    }
    ll mid = (low + high) >> 1;
    return seg[ind] = buildTree(2 * ind,low ,mid) + buildTree(2 * ind + 1,mid + 1,high);
}
void update(ll ind,ll low,ll high,ll pos,ll val) {
    if(pos > high || pos < low) {
        return;
    }
    if(low == high && low == pos){
        seg[ind] += val;
        return;
    }
    ll mid = (low + high) >> 1;
    update(2 * ind,low,mid,pos,val);
    update(2 * ind + 1,mid + 1,high,pos,val);
    seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
}
ll rangeSum(ll ind,ll low,ll high,ll l,ll r) {
    if(l > high || r < low) {
        return 0;
    }
    if(low >= l && high <= r) {
        return seg[ind];
    }
    int mid = (low + high) >> 1;
    return rangeSum(2 * ind,low,mid,l,r) + rangeSum(2 * ind + 1,mid + 1,high,l,r);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n,q;
    cin >> n >> q;
    arr.resize(n + 1);
    seg.resize(4 * n + 1);
    for(ll i = 1; i <= n; i++) {
        cin>>arr[i];
    }
    buildTree(1,1,n);
    while(q--) {
        ll queryType;
        cin >> queryType;
        if(queryType == 1) {
            ll k,u;
            cin >> k >> u;
            update(1,1,n,k,u - arr[k]);
            arr[k] = u;
        }
        else if(queryType == 2){
            ll l,r;
            cin >> l >> r;
            cout << rangeSum(1,1,n,l,r) << nl;
         }
    }
    return 0;
}