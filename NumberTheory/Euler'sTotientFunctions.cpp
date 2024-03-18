#include "bits/stdc++.h"
using namespace std;    
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int phi(int n) {
    int cnt = n;  
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while (n % i == 0)
                n /= i;
            cnt -= cnt / i;
        }
    }
    if(n > 1) {
        cnt -= cnt / n;
    }
    return cnt;
}
void phi_1_to_n(int n) {
    vector<int>phi(n + 1);
    for(int i = 0; i <= n; i++)
        phi[i] = i;

    for(int i = 2; i <= n; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a % b);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n = 10,cnt = 0;
    for(int i = 1; i <= n; i++) {
        int val = gcd(i,n);
        if(val == 1) {
            cnt++;
            // cout << i << " " << n << nl;
        }
    }
    //calculate euler's totient function 
    cout << cnt << nl; // brute force
    cout << phi(n) << nl; // optimize way  // TC - O(sqrt(n))
    phi_1_to_n(n); // calculate from 1 to n // TC - O(nloglogn)
    return 0;
}