#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int N = 1000000; 
int spf[N + 1];   
void createSieve() {   
	for(int i = 1; i <= N; i++) {
		spf[i] = i;		  
	}
	for(int i = 2; i * i <= N; i++) {
		if(spf[i] == i) {
			for(int j = i * i; j <= N; j += i) {
				if(spf[j] == j) {
					spf[j] = i;
				}
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
	int n = 30;
	while(n != 1) {
		cout << spf[n] << " ";
		n = n / spf[n];
	}
    return 0;
}

//TC: O(logN)
