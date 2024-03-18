#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///           
const int MOD = 1e9 + 7;
ll modular(ll x) { 
    return ((x % MOD + MOD) % MOD);
}
ll add(ll a,ll b) { 
    return modular(modular(a) + modular(b));
}
ll mul(ll a,ll b) { 
    return modular(modular(a) * modular(b));
}
ll N = 1e6 + 3;
vector<ll>fact(N + 1);
void preCompute() {
    fact[0] = 1;
    for(ll i = 1; i <= N; i++) {
        fact[i] = mul(fact[i - 1],i);
    }
}
ll findInverse(ll a) {
    ll fact = 1;
    ll b = MOD - 2;
    while(b > 0) {
        if(b & 1) {
            fact  = mul(fact,a);
        }
        a = mul(a,a);
        b >>= 1;
    }
    return fact;  
}
ll nCr(ll a,ll b) {  
    ll x = fact[a];
    ll y = mul(fact[b],fact[a - b]); 
    return mul(x,findInverse(y));
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    preCompute();
    int q;
    cin >> q;
    while(q--) {
        ll a,b;
        cin >> a >> b;
        cout << nCr(a,b) << nl;
    }
    return 0;
}

/*
I/P: 
3
5 3 
8 1
9 5
O/P:
10
8
126
*/