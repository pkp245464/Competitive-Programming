#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int countDigit(long n) {
	return floor(log10(n) + 1);
}
int countDigit1(long n) {
	if(n == 0) return 0;
	return 1 + countDigit1(n / 10);
}
int countDigit2(long n) {
	int cnt = 0;
	while(n!=0) {
		n = n/10;
		cnt++;
	}
	return cnt;
}
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a = 12435;
	int b = 123;
	int c = 123456789;
	cout << countDigit1(a) << nl;
	cout << countDigit1(b) << nl;
	cout << countDigit2(c) << nl;
	return 0;
}
