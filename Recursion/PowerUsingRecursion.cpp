#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------///
int fun(int a,int n) {
	if(n == 0) {
		return 1;
	}
	else {
		return fun(a,n - 1) * a;
	}
}
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int a = 2,n = 3;
	cout << fun(a,n) << nl;	
 	return 0;
}