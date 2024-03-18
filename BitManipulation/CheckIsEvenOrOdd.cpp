#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
bool isEvenUsingXOR(int n) {
    if((n ^ 1) == (n + 1)) return true;
    else return false;
}
bool isEvenUsingAND(int n) {
    return (!(n & 1));
}
bool isEvenUsingOR(int n) {
    if( (n | 1 ) > n) return true;
    else return false;
}
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for(int i=1;i<9;i++) {
        if(isEvenUsingAND(i)) cout<<"Even"<<nl;
        else cout<<"Odd"<<nl;
    }
    int n = 5;
    cout << (n >> 1) << nl; //divide by two
    cout << (n << 1) << nl; //multiply by two
    /*
    '>>' means  n/(2^i) // i=1,2,3,..n;
    '<<' means  n*(2^i) // i=1,2,3,..n;
    */
    return 0;
}

/*
1 ->  001     11 -> 1011
2 ->  010     12 -> 1100
3 ->  011     13 -> 1101
4 ->  100     14 -> 1110
5 ->  101     15 -> 1111
6 ->  110     16 -> 10000
7 ->  111     17 -> 10001
8 ->  1000    18 -> 10010
9 ->  1001    19 -> 10011
10 -> 1010    20 -> 10100
*/