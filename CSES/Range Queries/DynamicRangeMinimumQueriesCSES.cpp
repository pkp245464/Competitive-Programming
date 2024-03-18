/*Problem Link - "https://cses.fi/problemset/task/1649/"*/

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class SegmentedTree {
private:
    vector<int>seg;
public:
    SegmentedTree(int n) {
        seg.resize(4 * n + 1);
    }
    void build(int ind,int low,int high,vector<int>&arr) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1,low,mid,arr);
        build(2 * ind + 2,mid + 1,high,arr);
        seg[ind] = min(seg[2 * ind + 1],seg[2 * ind + 2]);
    }
    int query(int ind,int low,int high,int l,int r) {
        if(r < low || high < l) {
            return INT_MAX;
        }
        if(low >= l && high <= r) {
            return seg[ind];
        }
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1,low,mid,l,r);
        int right = query(2 * ind + 2,mid + 1,high,l,r);
        return min(left,right);
    }
    void update(int ind,int low,int high,int pos,int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(pos <= mid) {
            update(2 * ind + 1,low,mid,pos,val);
        }
        else {
            update(2 * ind + 2,mid + 1,high,pos,val);
        }
        seg[ind] = min(seg[2 * ind + 1],seg[2 * ind + 2]);
    }
};
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
        cin>>arr[i];
    }    
    SegmentedTree *p = new SegmentedTree(n);
    p->build(0,0,n - 1,arr);    
    while(q--) {
        int type;
        cin>>type;
        if(type == 1) {
            int ind,val;
            cin>>ind>>val;
            ind--;
            p->update(0,0,n - 1,ind,val);
            arr[ind] = val;
        }
        else if(type == 2) {
            int start,end;
            cin>>start>>end;
            start--,end--;
            cout<<p->query(0,0,n - 1,start,end)<<nl;
        }
    }
    return 0;
}