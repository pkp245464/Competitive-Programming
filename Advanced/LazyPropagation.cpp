//Here Update Query means adding to value into existing element from l to r.
#include<bits/stdc++.h>
using namespace std;
#define lli long long int  
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class SegmentedTree {
private:
    vector<int>seg,lazy;
public:
    SegmentedTree(int n) {
        seg.resize(4 * n);
        lazy.resize(4 * n);
    }
    void build(int ind,int low,int high,vector<int>&arr) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1,low,mid,arr);
        build(2 * ind + 2,mid + 1,high,arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    void update(int ind,int low,int high,int l,int r,int val) {
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
        int mid = low + (high - low) / 2;
        update(2 * ind + 1,low,mid,l,r,val);
        update(2 * ind + 2,mid + 1,high,l,r,val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    int query(int ind,int low,int high,int l,int r) {
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
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1,low,mid,l,r);
        int right = query(2 * ind + 2,mid + 1,high,l,r);
        return left + right;
    }
};
int main(){
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    SegmentedTree *p = new SegmentedTree(n + 1);
    p->build(0,0,n - 1,arr);

    int q;
    cin>>q;
    while(q--) {
        int type;
        cin>>type;
        if(type == 1) {
            int l,r;
            cin>>l>>r;
            cout<<p->query(0,0,n - 1,l,r)<<nl;
        }
        else {
            int l,r,val;
            cin>>l>>r>>val;
            p->update(0,0,n - 1,l,r,val);
        }
    }
    return 0;
}
/*
I/P:
5
1 2 3 4 5
3
1 0 4
2 1 3 2   //1 4 5 6 5 //here update means adding the value to existing element
1 0 4
O/P:
15
21
*/


