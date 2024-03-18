
/*Problem Linke - "https://cses.fi/problemset/task/1646" */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
vector<ll>arr;
void rangeSum() {
    for(ll i = 1; i < arr.size(); i++) {
        arr[i] = arr[i - 1] + arr[i];
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n,q;
    cin >> n >> q;
    arr.resize(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rangeSum();
    while(q--) {
        ll a,b,sum = 0;
        cin >> a >> b;
        if(a - 1 == 0) {
            cout << arr[b - 1] << nl;;
        }
        else {
            cout << arr[b - 1] - arr[a - 2] << nl;
        }
    }
    return 0;
}