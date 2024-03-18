#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(3);
    auto dist = [](int x1, int y1, int x2, int y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };

    int x1 = 3,y1 = 4;
    int x2 = 14,y2 = 18;
    int r1 = 5,r2 = 15;
    
    double d =  dist(3,4,14,18);
    
    cout << d << nl;

    if (d <= r1 - r2) {
        cout << "Circle B is inside A";
    }
    else if (d <= r2 - r1) {
        cout << "Circle A is inside B";
    }
    else if (d < r1 + r2) {
        cout << "Circle intersect to each other";
    }
    else if (d == r1 + r2) {
        cout << "Circle touch to each other";
    }
    else {
        cout << "Circle not touch to each other";
    }
    return 0;
}