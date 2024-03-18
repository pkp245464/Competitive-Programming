#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------///
void TOH(int n,int a,int b,int c) {
	if(n > 0) {
		TOH(n - 1,a,c,b);
		cout << a << " " << c << nl;
		TOH(n - 1,b,a,c);
	}
}
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int n = 3,a = 1,b = 2,c = 3;
	TOH(n,a,b,c);
 	return 0;
}
