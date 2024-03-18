#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
ll rangeBitwiseAnd(ll left, ll right) {
    ll ans = 0; 
    for(ll bit = 61; bit >= 0; bit--) {
        if((left & (1LL << bit)) != (right & (1LL << bit))) {
            break;
        }
        else {
            ans |= (left & (1LL << bit));
        }
    }
    return ans;
}
//Or
// ll rangeBitwiseAnd(ll left,ll right) {
//     ll ans = 0;
//     for(ll bit = 61; bit >= 0; bit--) {
//         if((left >> bit & 1ll) && (left >> bit) == (right >> bit)) {
//             ans |= 1ll << bit;
//         }
//     }
//     return ans;
// }
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll left = 5,right = 7;
    cout << (5 & 6 & 7) << nl; // O/P: 4
    cout << rangeBitwiseAnd(left,right) << nl; // O/P: 4         
    return 0;
}