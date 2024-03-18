#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int cntSetBit(int n) {
    int cnt = 0;
    while(n > 0) {
        if(n % 2 !=0) {
            cnt++;
        }
        n /= 2;
    }
    return cnt;
}
int cntSetBit(int n) {
    int cnt = 0;
    while(n > 0) {
        if((n & 1) == 1) cnt++;
        //cnt += (n & 1) :we can write in this ways.
        n = n >> 1;
    }
    return cnt;
}
int cntSetBitUsingKernighan(int n) {
        int cnt = 0;
        while(n > 0) {
            n = (n & (n - 1));
            cnt++;
        }
        return cnt;
}
int table[256];
void initialize() {
    table[0] = 0;
    for(int i = 1; i < 256; i++) {
        table[i] = (i & 1) + table[i / 2];
    }
}
int countBitUsingLookUpTable(int n) {
    int cnt = table[n&0xff];
    n = n >> 8;
    cnt = cnt + table[n&0xff];
    n = n >> 8;
    cnt = cnt + table[n&0xff];
    n = n >> 8;
    cnt = cnt + table[n&0xff];
    return cnt;
}
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n = 7;
    cout << cntSetBit(n) << nl;
    cout << countBitUsingBitwise(n) << nl;
    cout << countBitUsingKerningams(n) << nl;
    cout<<__builtin_popcount(n)<<nl; 
    
    initialize();
    cout << countBitUsingLookUpTable(n) << nl;

    return 0;
}

/*
Q.1) Count the set bits from l to r;
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int countSetBits(int n) {
    int cnt = 0;
    while(n > 0) {
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int l,r,cnt = 0;
    cin >> l >> r;
    for(int i = l; i <= r; i++) {
        if((i & 1) == 0 && i < r) {
            cnt += 2 * countSetBits(i) + 1;
            i++;
        }
        else {
            cnt += countSetBits(i);
        }
    }
    cout << cnt << nl;
    return 0;
}
//l = 10,r = 15
// 10 -> 1010 - 2
// 11 -> 1011 - 3
// 12 -> 1100 - 2
// 13 -> 1101 - 3
// 14 -> 1110 - 3
// 15 -> 1111 - 4
//Total SetBit:17
*/