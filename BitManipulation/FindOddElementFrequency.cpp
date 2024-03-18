/*
Given an array a of n integers. All integers are present in event count except one.
Find that one integer which has odd count in O(N) time complexity and O(1) space;
N < 10 ^ 5
a[i] < 10 ^5
*/

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double 
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n,x,ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		ans ^= x;
	}
	cout << ans << nl;
	return 0;
}