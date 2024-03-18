/*Problem Link - "https://cses.fi/problemset/task/1651/"*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long  
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class SegmentedTree {
private:
    vector<ll>seg,lazy;
public:
    SegmentedTree(ll n) {
        seg.resize(4 * n);
        lazy.resize(4 * n);
    }
    void build(ll ind,ll low,ll high,vector<ll>&arr) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2 * ind + 1,low,mid,arr);
        build(2 * ind + 2,mid + 1,high,arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    void update(ll ind,ll low,ll high,ll l,ll r,ll val) {
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(high < l || r < low) {
            return;
        }
        if(low >= l && high <= r) {
            seg[ind] += (high - low + 1) * val;
            if(low != high) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        ll mid = low + (high - low) / 2;
        update(2 * ind + 1,low,mid,l,r,val);
        update(2 * ind + 2,mid + 1,high,l,r,val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    ll query(ll ind,ll low,ll high,ll l,ll r) {
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(high < l || r < low) {
            return 0;
        }
        if(low >= l && high <= r) {
            return seg[ind];
        }
        ll mid = low + (high - low) / 2;
        ll left = query(2 * ind + 1,low,mid,l,r);
        ll right = query(2 * ind + 2,mid + 1,high,l,r);
        return left + right;
    }
};
int main(){
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ll n,q;
    cin >> n >> q; 
    vector<ll>arr(n);
    for(ll i = 0; i < n; i++) {
        cin>>arr[i];
    }
    SegmentedTree *p = new SegmentedTree(n + 1);
    p->build(0,0,n - 1,arr);
    while(q--) {
        ll type;
        cin>>type;
        if(type == 1) {
            ll l,r,val;
            cin >> l >> r >> val;
            l--,r--;
            p->update(0,0,n - 1,l,r,val);
        }
        else if(type == 2) {
            ll ind;
            cin >> ind;
            ind--;
            cout<<p->query(0,0,n - 1,ind,ind)<<nl;
        }
    }
    return 0;
}