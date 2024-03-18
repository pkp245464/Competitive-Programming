//printing 1 to n
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
void fun(int n) {
    if(n > 0) {
        fun(n - 1);
        cout << n << " ";
    }
}
int main(){
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n = 10;
    fun(n);
    return 0;
}
//output:1 2 3 4 5 6 7 8 9 10

//printing n to 1
void fun(int n) {
    if(n > 0) {
        cout << n << " ";
        fun(n - 1);
    }
}
//output:10 9 8 7 6 5 4 3 2 1

//printing n to 1 without recursion & loop;
void fun(int n) {
    start:
    if(n > 0) {
        cout << n << " ";
        n = n - 1;
        goto start;
    }
}
//output:10 9 8 7 6 5 4 3 2 1

//printing 1 to n using tail recursion
void fun(int n,int k = 1) {
    if(n < 1) return;
    cout << k << " ";
    fun(n - 1,k + 1);
}
//output:1 2 3 4 5 6 7 8 9 10 