#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int maxProfit(vector<int>& prices) {
	int maxi = INT_MIN;
	int mini = INT_MAX;
	for(int i = 0; i < prices.size(); i++) {
		mini = min(mini,prices[i]);
		maxi = max(maxi,prices[i] - mini);
	}
	return maxi;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {7,1,5,3,6,4};
    cout << maxProfit(arr) << nl;
    return 0;
}
