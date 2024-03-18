#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//Method 1
bool isPow2(int n) {
    if(n == 0) {
        return false;
    }
    while(n != 1) {
        if(n % 2 != 0) {
            return false;
        }
        n /= 2;
    }
    return true;
}
//Method 2
bool isPow2(int n) {
    return (n != 0) && ((n & (n - 1)) == 0);
}
int main(){
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n = 16; 
    cout << (isPow2(n) ? "YES" : "NO") << nl;
    return 0;
}

