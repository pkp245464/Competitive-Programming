#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
ll distanceBetweenTwoPoint(ll x1,ll y1,ll x2,ll y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld dist =  distanceBetweenTwoPoint(x1,y1,x2,y2);
    dist = sqrtl(dist);
	cout << dist << nl;
    return 0;
}