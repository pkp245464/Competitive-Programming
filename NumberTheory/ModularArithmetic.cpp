#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int MOD = 1e9 + 7;
ll modular(ll x) { // handle both postive and negative number with mod
    return ((x % MOD + MOD) % MOD);
}
ll add(ll a,ll b) { //add two number with modulo
    return modular(modular(a) + modular(b));
}
ll mul(ll a,ll b) { //mul two number with modulo
    return modular(modular(a) * modular(b));
}
ll sub(ll a,ll b) { ////sub two number with modulo
	return modular(modular(a) - modular(b));
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n = -15;
    cout << n % MOD << nl; // wrong method //O/P: 999999992 (right)
    cout << mod(n) << nl; //right method  //O/P: -15 (wrong)
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long  
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int M = 1e9 + 7;
class Solution {
public:
    ll findInverse(ll a) {
        ll ans = 1;
        ll b = M - 2;  
        while(b > 0) {
            if(b & 1) {
                ans = (ans * 1LL * a) % M;
            }
            a = (a * 1LL * a) % M;
            b >>= 1;
        }
        return ans;
    }
    void modularArithmetic(ll a,ll b) {
        //Addition
        // (a + b) % M = ((a % M) + (b % M)) % M
        cout<<"Addition: "<<((a % M) + (b % M)) % M<<nl;
        
        //Subraction
        // (a - b) % M = ((a % M) - (b % M) + M) % M
        cout<<"Subtraction: "<<((a % M) - (b % M) + M) % M<<nl;

        //Multiplication
        // (a * b) % M = ((a % M) * (b % M)) % M
        cout<<"Multiplication: "<<((a % M) * (b % M)) % M<<nl;
        
        //Division
        //(a / b) % M = ((a % M) * ((b ^ -1) % M)) % M
        cout<<"Division: "<<((a % M) * (findInverse(b) % M)) % M<<nl;
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    ll a = 154268430874189;
    ll b = 415312161340133;
    p->modularArithmetic(a,b);  
    return 0;
}
*/