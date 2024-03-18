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
    printBinary(9); //binary repesentation of number
    printBinary(~9); //invert bit
    int a = 7;
    int i = 3;
    //check ith bit is set or not
    if((a &(1 << i)) != 0) {
        cout<<"set bit"<<nl;
    }
    else {
        cout<<"not set bit"<<nl;
    }
    // Set ith Bit
    printBinary(a | (1 << 5));  // 5th bit of a
    //Unset ith bit
    printBinary(a & ( ~ (1 << 5))); //5th bit of a
    //toggle ith ith bit  //
    printBinary(a ^ (1 << 5));  // 5th bit toggle 0 to 1 vice vers
    return 0;
}

