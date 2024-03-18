#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//TC - log(b) binaryExponentiationRecursive
ll BER(ll a,ll b) { 
	if(b == 0) {
		return 1;
	}
	ll ans = BER(a,b/2);
	if(b & 1) {  
		return ans * ans * a;
	}
	else {
		return ans * ans;
	}
}
//TC - log(b) //binaryExponentiationIterative
ll BEI(ll a,ll b) { 
	ll ans = 1;
	while(b > 0) {
		if(b & 1) {
			ans = ans * a;
		}
		a = a * a;
		b >>= 1;
	}
	return ans;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll a = 2;
    ll b = 3;
    cout << BER(a,b) << nl;
    cout << BEI(a,b) << nl;
    return 0;
}
