#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int N = 1000000; 
vector<bool>sieve(N + 1,true);
void createSieve() {
    sieve[0] = sieve[1] = false;
    for(int i = 2; i*i <= N; i++) {
        if(sieve[i] == true) {
            for(int j = i*i; j <= N; j += i) {
                sieve[j] = false;
            }  
        }
    }
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    createSieve();
    int start = 1,end = 100;
    for(int i = start; i <= end; i++) {
        if(sieve[i]) {
            cout << i << " \n"[i == 100];
        }
    }
    return 0;
}
