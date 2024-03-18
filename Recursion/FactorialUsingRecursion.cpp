#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int n) {
    if(n == 0) {
        return 1;
    } 
    else {
        return n * fun(n - 1);
    }
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n = 5;
    cout << fun(n) << nl;
    return 0;
}
//output:120

//Printing factorial using trail recursion
int fun(int n,int val = 1) {
    if(n == 0) {
        return val;
    } 
    else {
        return fun(n - 1,n * val);
    }
}
//output:120