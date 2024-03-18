/*
There is a directed graph G with N vertices and M edges. The vertices are numbered 1,2,…,N, and for each 
i(1 ≤ i ≤M), the i-th directed edge goes from Vertex Xi to Yi.G does not contain directed cycles.Find the 
length of the longest directed path in G. Here, the length of a directed path is the number of edges in it.

https://atcoder.jp/contests/dp/tasks/dp_g
*/

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int N = 1e5 + 3;
vector<int>dp(N);
vector<vector<int>>adj(N);
int DFS(int u) {
    if(dp[u]) {
        return dp[u];
    }
    for(auto v : adj[u]) {
        dp[v] = DFS(v);
        dp[u] = max(dp[u],dp[v] + 1); 
    }
    return dp[u];
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        DFS(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans << nl;
    return 0;
}