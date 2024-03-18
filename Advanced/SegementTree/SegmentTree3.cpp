/*
//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C

Two integers n and m(1≤n,m≤100000), the size of the array and the number of operations. The next
line contains n numbers a[i],the initial state of the array (0≤a[i]≤109).

1) i,v : set the element with index i to v  (0≤i<n,0≤v≤1e9).
2) l,r : calculate the minimum and number of elements equal to minimum of elements with indices 
         from l to r − 1 (0≤l<r≤n).

I/P:
5 5
3 4 3 5 2
2 0 3
1 1 2
2 0 3
1 0 2
2 0 5

O/P:
3 2
2 1
2 3
*/

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
struct item {
    int m,c;
};
struct segtree {
    int sz;
    vector<item>seg;
    item NEUTRAL_ELEMENT = {INT_MAX,0};
    item merge(item a,item b) {
        if(a.m < b.m) return a;
        if(a.m > b.m) return b;
        return {a.m,a.c + b.c};
    }
    item single(int v) {
        return {v,1};
    }
    void init(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        seg.resize(2 * sz);
    }
    void build(vector<int>&a,int x,int lx,int rx) {
        if(rx - lx == 1) {
            if(lx < (int)a.size()) {
                seg[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a,2 * x + 1,lx,m);
        build(a,2 * x + 2,m,rx);
        seg[x] = merge(seg[2 * x + 1],seg[2 * x + 2]);
    }
    void build(vector<int>&a) {
        build(a,0,0,sz);
    }
    void set(int i,int v,int x,int lx,int rx) {
        if(rx - lx == 1) {
            seg[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i,v,2 * x + 1,lx,m);
        }
        else {
            set(i,v,2 * x + 2,m,rx);
        }
        seg[x] = merge(seg[2 * x + 1],seg[2 * x + 2]);
    }
    void set(int i,int v) {
        set(i,v,0,0,sz);
    }
    item calc(int l,int r,int x,int lx,int rx) {
        if(lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        item s1 = calc(l,r,2 * x + 1,lx,m);
        item s2 = calc(l,r,2 * x + 2,m,rx);
        return merge(s1,s2);
    }
    item calc(int l,int r) {
        return calc(l,r,0,0,sz);
    }
};
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin >> n >> m;
    segtree sg;
    sg.init(n);
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sg.build(a);
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i,v;
            cin >> i >> v;
            sg.set(i,v);
        }
        else {
            int l,r;
            cin >> l >> r;
            auto ans = sg.calc(l,r);
            cout << ans.m << " " << ans.c << nl;
        }
    }
    return 0;
}