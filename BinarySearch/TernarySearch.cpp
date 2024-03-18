#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int ternarySearch(vector<int>&a,int target) {
    int l = 0,r = a.size() - 1;
    while(l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 2;
        if(a[m1] == target) {
            return m1;
        }
        if(a[m2] == target) {
            return m2;
        }
        if(target < a[m1]) {
            r = m1 - 1;
        }
        else if(target > a[m2]) {
            l = m2 + 1;
        }
        else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    return  -1;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int target = 70;
    vector<int>a = {10,20,30,40,50,60,70,80,81};
    cout << ternarySearch(a,target) << nl;
    return 0;
}