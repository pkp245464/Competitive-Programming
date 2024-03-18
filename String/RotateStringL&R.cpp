#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
string rotateLeft(string s, int d) {
    rotate(s.begin(),s.begin() + d,s.end());   
    return s;
} 
string rotateRight(string s, int d) {
    rotate(s.rbegin(),s.rbegin() + d,s.rend()); 
    return s;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "ABCDEF";
    cout << rotateLeft(s,1) << nl;
    cout << rotateRight(s,1) << nl;
    return 0;
}