/*
//Fermat's little
given a = 2,b = 4,c = 3,mod = 23
a ^ b ^ c = ?
b ^ c = 4 ^ 3 = 64
a ^ 64 = 18446744073709551616 % mod = 6 //ans

if we calculate like that, then this wrong method
x = (b ^ c) % mod //wrong method
ans = (a ^ x) % mod

Note: An Efficient approach is to reduce the (b ^ c) to a smaller value 
	by using the Fermat’s Little Theorem, and then apply Modular exponential.
According the Fermat's little
a(M - 1) = 1 (mod M) if M is a prime.


Correct way to calculate
x = (a ^ c) % (mod - 1) //Fermat's little
ans = (a ^ x) % mod 

*/	


//https://cses.fi/problemset/task/1712
//https://www.geeksforgeeks.org/find-power-power-mod-prime/

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
ll BEI(ll a,ll b,ll mod) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--) {
        ll a,b,c,mod = 1e9 + 7;
        cin >> a >> b >> c;
        ll val = BEI(b,c,mod - 1); //Fermat's little
        cout << BEI(a,val,mod) << nl;
    }
    return 0;
}