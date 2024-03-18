#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void powerSet(string s) {
    int n = s.size();
    int powSize = 1 << n;
    for(int i = 0; i < powSize; i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j))
                cout << s[j] << ' ';
        }
        cout << nl;
    }
}
int main(){
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    string s = "ABC";
    powerSet(s);
    return 0;
}