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
    int n;
    cin >> n;
    vector<string>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),[](const string a,const string b) {
        if(a.size() != b.size()) {
            return a.size() < b.size();
        }
        else {
            return a<b;
        }
    });
    for(int i = 0; i < n; i++) {
        cout << arr[i] << nl;
    }
    return 0;
}
/*
Test Case:-
INPUT: 
8
1
2
100
12303479849857341718340192371
3084193741082937
3084193741082938
111
200
OUTPUT:
1
2
100
111
200
3084193741082937
3084193741082938
12303479849857341718340192371
*/

















