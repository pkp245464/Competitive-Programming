#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//TC: O(N * N!)
void stringPermutation(int l,int r,string s) {
    if(l == r) {
        cout << s << nl;
    }
    else {
        for(int i = l; i <= r; i++) {
            swap(s[l],s[i]);
            stringPermutation(l + 1,r,s);
            swap(s[l],s[i]);
        }
    }
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "ABC";
    int n = s.size();
    stringPermutation(0,n - 1,s);
    return 0;
}
/*
I/P:
s = "ABC"
O/P:
ABC
ACB
BAC
BCA
CBA
CAB
*/