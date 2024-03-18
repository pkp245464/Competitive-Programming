#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//TC: O(1)  
int countOdds(int l, int h) {
    int odd = (h - l) / 2;
    if(l % 2 || h % 2) {
        odd++;
    }
    return odd;  
}
//TC: O(1) better way
// int countOdds(int l, int h) {
//     return ((h + 1) / 2) - (l / 2);
// }
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int l = 3,h = 9; 
    int odd = countOdds(l,h);
    int even = (h - l + 1) - odd;
    cout << even << " " << odd << nl;
    return 0;
}