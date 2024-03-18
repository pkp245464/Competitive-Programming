#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void printBinary(int num) {
    for(int i = 10; i >= 0; i--) {
        cout << ((num >> i ) & 1);
    }
    cout << nl;
}
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    printBinary(59);
    
    //Clear Nth Bit of LSB
    int a = 59;
    int i = 4;
    int b = (a & (~((1 << (i + 1)) - 1)));
    printBinary(b);
    
    //CLear Nth Bit of MSB
    int j = 3;
    int c = (a & ((1 << (j + 1)) - 1));
    printBinary(c);
    return 0;
}

