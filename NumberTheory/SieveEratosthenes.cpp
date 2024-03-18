#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int N = 1000000;
bool sieve[1000001];  
void createSieve() {
	for(int i = 2; i <= N; i++) {
		sieve[i] = true;
	}
	for(int i = 2; i * i <= N; i++) {
		if(sieve[i] == true) {
			for(int j = i * i; j <= N; j += i) {
				sieve[j] = false;
			}
		}
	}
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	createSieve();
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		if(sieve[n] == true) {
			cout << "Yes" << nl;
		}
		else {
			cout << "No" << nl;
		}
	}
	return 0;
}
