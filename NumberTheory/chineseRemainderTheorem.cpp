#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//TC: O(n * n * log(b))
ll findInverse(ll a,ll m) {
    ll fact = 1;
    ll b = m - 2;
    while(b > 0) {
        if(b & 1) {
            fact  = (fact * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return fact;  
}
ll chineseRemainderTheorem(vector<pair<ll,ll>>&vp) {
    ll m = 1;
    for(ll i = 0; i < vp.size(); i++) {
        m *= vp[i].first;
    }
    ll ans = 0;
    for(ll i = 0; i < vp.size(); i++) {
        ll t = 1;
        for(ll j = 0; j < i; j++) {
            t *= vp[j].first;
            t *= findInverse(vp[j].first,vp[i].first);
            t %= m;
        }
        ans += (t * (vp[i].second + m - ans)) % m;
        ans %= m;
    }
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<pair<ll,ll>>vp = {{5,1},{7,1},{11,3}}; 
    cout << chineseRemainderTheorem(vp) << nl;   
    return 0;
}


/*
find the x ? {{2,1},{3,2},{5,3}}
x % 2 = 1
x % 3 = 2
x % 5 = 3

Sol: 23
*/