/*
//Closest to left
Given an array of n numbers, sorted in non-decreasing order, and k queries.For each query,
print the maximum index of an array element not greater than the given one.
I/P:
5 5
3 3 5 8 9
2 4 8 1 10
O/P:  
0
2
4
0    
5
*/
//Code Begins
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
    int n,q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int l = -1; //a[l] <= x
		int r = n;  //a[r] > x
        while(l + 1 < r) {
            int m = l + (r - l) / 2;
            if(a[m] <= x) {
                l = m;
            }
            else {
                r = m;
            }
        }
        cout << l + 1 << nl;
    }
    return 0;
}

/*
//Closest to right
Given an array of n numbers, sorted in non-decreasing order, and k queries. For each query,
print the minimum index of an array element not less than the given one.
I/P:
5 5
3 3 5 8 9
2 4 8 1 10
O/P:
1
3
4
1
6
*/
//Code Begins
#include "bits/stdc++.h"
using namespace std;  
#define ll long long 
#define llu unsigned long long int
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
    int n,q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int l = -1; //a[l] < x
		int r = n; //a[r] >= x
        while(l + 1 < r) {
            int m = l + (r - l) / 2;
            if(a[m] < x) {
                l = m;
            }
            else {
                r = m;
            }
        }
        cout << r + 1 << nl;
    }
    return 0;
}