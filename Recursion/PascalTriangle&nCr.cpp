#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------///
int pascalTriangle(int n,int r) {
	if(n == r || r == 0) {
		return 1;
	} 
	return pascalTriangle(n - 1,r - 1) + pascalTriangle(n - 1,r);
}
int fact(int n) {
	if(n == 0) {
		return 1;
	} 
	return fact(n - 1) * n;
}
int nCr(int n,int r) {
	int num,den;
	num = fact(n);
	den = fact(r) * fact(n - r);
	return num / den;
}
int combination(int n,int r) {
	int t1,t2,t3;
	t1 = fact(n);
	t2 = fact(r);
	t3 = fact(n - r);
	return t1 / (t2 * t3);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int n = 5,r = 4;
	cout << pascalTriangle(n,r) << nl;
	cout << nCr(n,r) << nl;
	cout << combination(n,r) << nl;	
 	return 0;
}