//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int maxWeight,vector<int>&weight,vector<int>&values) {
	if(ind == 0) {
		if(weight[0] <= maxWeight) {
			return values[0];
		}
		return 0;
	}
	int notTake = 0 + fun(ind - 1,maxWeight,weight,values);
	int take = 0;
	if(weight[ind] <= maxWeight) {
		take = values[ind] + fun(ind - 1,maxWeight - weight[ind],weight,values);
	}
	return max(take,notTake);
}
int knapSack(int maxWeight,vector<int>&weight,vector<int>&values) {
	return fun(weight.size() - 1,maxWeight,weight,values);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int maxWeight = 5;
    vector<int>weight = {1,2,4,5};
    vector<int>values = {5,4,8,6};
    cout << knapSack(maxWeight,weight,values) << nl;   
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Memoization Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int maxWeight,vector<int>&weight,vector<int>&values,vector<vector<int>>&dp) {
	if(ind == 0) {
		if(weight[0] <= maxWeight) {
			return values[0];
		}
		return 0;
	}
	if(dp[ind][maxWeight] != -1) {
		return dp[ind][maxWeight];
	}
	int notTake = 0 + fun(ind - 1,maxWeight,weight,values,dp);
	int take = 0;
	if(weight[ind] <= maxWeight) {
		take = values[ind] + fun(ind - 1,maxWeight - weight[ind],weight,values,dp);
	}
	return dp[ind][maxWeight] = max(take,notTake);
}
int knapSack(int maxWeight,vector<int>&weight,vector<int>&values) {
	int n = weight.size();
	vector<vector<int>>dp(n,vector<int>(maxWeight + 1,-1));
	return fun(n - 1,maxWeight,weight,values,dp);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int maxWeight = 5;
    vector<int>weight = {1,2,4,5};
    vector<int>values = {5,4,8,6};
    cout << knapSack(maxWeight,weight,values) << nl;   
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Tabulation Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int knapSack(int maxWeight,vector<int>&weight,vector<int>&values) {
	int n = weight.size();
	vector<vector<int>>dp(n,vector<int>(maxWeight + 1,0));

	for(int i = weight[0]; i <= maxWeight; i++) {
		dp[0][i] = values[0];
	}

	for(int ind = 1; ind < n; ind++) {
		for(int cap = 0; cap <= maxWeight; cap++) {
			int notTake = 0 + dp[ind - 1][cap];
			int take = 0;
			if(weight[ind] <= cap) {
				take = values[ind] + dp[ind - 1][cap - weight[ind]];
			}
			dp[ind][cap] = max(take,notTake);
		}
	}
	return dp[n - 1][maxWeight];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int maxWeight = 5;
    vector<int>weight = {1,2,4,5};
    vector<int>values = {5,4,8,6};
    cout << knapSack(maxWeight,weight,values) << nl;   
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Space Optimization Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int knapSack(int maxWeight,vector<int>&weight,vector<int>&values) {
	int n = weight.size();
	vector<int>prev(maxWeight + 1,0);
	for(int i = weight[0]; i <= maxWeight; i++) {
		prev[i] = values[0];
	}
	for(int ind = 1; ind < n; ind++) {
		for(int cap = maxWeight; cap >= 0; cap--) {
			int notTake = 0 + prev[cap];
			int take = 0;
			if(weight[ind] <= cap) {
				take = values[ind] + prev[cap - weight[ind]];
			}
			prev[cap] = max(take,notTake);
		}
	}
	return prev[maxWeight];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int maxWeight = 5;
    vector<int>weight = {1,2,4,5};
    vector<int>values = {5,4,8,6};
    cout << knapSack(maxWeight,weight,values) << nl;   
    return 0;
}
*/