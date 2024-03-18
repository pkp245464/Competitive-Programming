/*Problem Link :- https://cses.fi/problemset/task/1143/*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
vector<ll>arr;
vector<ll>seg;
bool isoverlap(ll a,ll b,ll x,ll y) {
    if(x >= a && x <= b) {
        return true;
    }
    if(a >= x && a <= y ) {
        return true;
    }
    return false;
}
ll build(ll ind,ll low,ll high) {
    if(low == high){
        seg[ind] = arr[low];
        return seg[ind];
    }
    ll mid = low + (high - low) / 2;
    ll ans1 = build(ind * 2,low,mid);
    ll ans2 = build((ind * 2) + 1,mid + 1,high);
    seg[ind] = max(ans1,ans2);
    return max(ans1,ans2);
}
ll update(ll ind,ll low,ll high,ll pos,ll val) {
    if(low == high && low == pos) {
        seg[ind] = seg[ind] - val;
        arr[pos] = arr[pos] - val;
        return seg[ind];
    }
    if(pos < low || pos > high) {
        return seg[ind];
    }
    if(low == high) {
        return arr[low];
    }
    ll mid = low + (high - low) / 2;
    ll ans1 = update(ind * 2,low,mid,pos,val);
    ll ans2 = update((ind * 2) + 1,mid + 1,high,pos,val);
    seg[ind] = max(ans1,ans2);
    return seg[ind];
}
ll query(ll ind,ll low,ll high,ll val){
    if(seg[ind] < val) {
        return 0;
    }
    if(low == high) {
        return low;
    }
    ll mid = low + (high - low) / 2;
    if(seg[ind * 2] >= val) {
        return query(ind * 2,low,mid,val);
    }
    else {
        return query((ind * 2) + 1,mid + 1,high,val);
    }
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
        cin >> arr[i];
    }
    build(1,1,n);
    while(q--) {
        ll groupOfPeople;
        cin >> groupOfPeople;
        ll pos = query(1,1,n,groupOfPeople);
        cout << pos << " \n"[q == 0];
        update(1,1,n,pos,groupOfPeople);
    }
    return 0;
}