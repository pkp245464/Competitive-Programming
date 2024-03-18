#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//shoelace formula
//TC: O(n)
ld areaOfPolygon(int n,vector<ll>&X,vector<ll>&Y) {
    ld ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (X[i] * Y[(i + 1) % n]);
        ans -= (X[(i + 1) % n] * Y[i]);
    }
    return abs(ans) / 2.0;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ll>X(n),Y(n);
    for(int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    } 
    cout << fixed << setprecision(9) << areaOfPolygon(n,X,Y) << nl;
    return 0;
}