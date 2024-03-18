// https://www.codechef.com/problems/REVERSE
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
constexpr int N = 1e5 + 3;
constexpr int INF = 1e9;
int n,m; 
vector<int>dist(N,INF);
vector<pair<int,int>>adj[N];
int bfs() {
    deque<int>dq;
    dq.push_back(1);
    dist[1] = 0;
    while(!dq.empty()) {
        int node = dq.front();
        dq.pop_front();
        for(auto it : adj[node]) {
            int child = it.first;
            int weight = it.second;     
            if(dist[node] + weight < dist[child]) {
                dist[child] = dist[node] + weight;
                if(weight == 1) {
                    dq.push_back(child);
                }
                else {
                    dq.push_front(child);
                }
            }

        }
    }
    return dist[n] == INF ? -1 : dist[n];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        if(u == v) continue; // no need add self loop
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    cout << bfs() << nl;
    return 0;
}