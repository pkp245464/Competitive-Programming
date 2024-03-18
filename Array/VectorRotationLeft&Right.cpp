//https://codeforces.com/problemset/problem/1511/C
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int rotL = 3;
    vector<int> a{1,2,3,4,5,6,7,8,9};
    rotate(a.begin(),a.begin() + rotL,a.end());
    
    cout << "Left rotation: ";
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " \n"[i + 1 == a.size()];
    }
    
    int rotR = 4;
    vector <int> b{1,2,3,4,5,6,7,8,9};
    rotate(b.begin(),b.begin() + b.size() - rotR,b.end());
    
    cout << "Right rotation: ";
    for(int i = 0; i < b.size(); i++) {
        cout << b[i] << " \n"[i == b.size() - 1]; 
    }
    return 0;
}
