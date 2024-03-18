/*  
There are n rectangles of the same size: w in width and h in length. It is required to find a square of
the smallest size into which these rectangles can be packed. Rectangles cannot be rotated.
I/P: 2 3 10
O/P: 9  
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
ll w,h,n; 
bool good(ll x) {
    return (x / w) * (x / h) >= n;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    cin >> w >> h >> n;
    ll l = 0,r = 1;
    while(!good(r)) {
        r *= 2;
    }
    while(l + 1 < r) {
        ll m = l + (r - l) / 2;
        if(good(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << r << nl;
    return 0;
}