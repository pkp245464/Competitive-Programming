//Reursive Approach
// Time Complexity: O(3^n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;  
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"  
#define fastinput ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//----------------------------------------------------------------//
int catalan(int n) {
	if(n <= 1) {
		return 1;
	}
	int ans = 0;
	for(int i = 0; i <= n - 1; i++) {
		ans += catalan(i) * catalan(n - i - 1);
	}
	return ans;
}
int main() {
	for(int i = 0; i < 10; i++) {
		cout<<catalan(i)<<nl;
	}
	return 0;
}
// O/P: 1 1 2 5 14 42 132 429 1430 4862 

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

// Memoization Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
/*
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
int catalan(int n) {
	vector<int>dp(n+1);
	if(n <= 1) {
		return 1;
	}
	if(dp[n]) {
		return dp[n];
	}
	for(int i = 1; i <= n; i++) {
		dp[n] += catalan(i - 1) * catalan(n - i);
	}
	return dp[n];
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	for(int i = 0; i < 10; i++) {
		cout<<catalan(i)<<nl;
	}
	return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

// Tabulation Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
/*
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
int catalan(int n) {
	vector<int>dp(n+1);
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	return dp[n];
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	for(int i = 0; i < 10; i++) {
		cout<<catalan(i)<<nl;
	}
	return 0;
}
*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

// Catalan Numbers
// Time Complexity: O(n)
// Space Complexity: O(1)
/*
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
int nCr(int n,int r) {
	int ans = 1;
	for(int i = 0; i < r; i++) {
		ans *= n - i;
		ans /= i + 1;
	}
	return ans;
}
int catalan(int n) {
	return nCr(2 * n, n) / (n + 1);
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	for(int i = 0; i < 10; i++) {
		cout<<catalan(i)<<nl;
	}
	return 0;
}
*/