//Brute Force Approach
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
    void addEdge(int u,int v,int wt,vector<pair<int,int>>adj[]) {
        adj[u].push_back({v,wt});
        adj[v].push_back({v,wt});
    }
    void MSTUsingPrimsAlgorithm(int N,vector<pair<int,int>>adj[]) {
        vector<int>parent(N);
        vector<int>key(N);
        vector<bool>mstSet(N);
        for(int i = 0; i < N; i++) {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }
        key[0] = 0;
        parent[0] = 0;
        int ansWeight = 0;
        for(int cnt = 0; cnt < N - 1; cnt++) {
            int u,mini = INT_MAX;
            for(int v = 0; v < N; v++) {
                if(mstSet[v] == false && key[v] < mini) {
                    mini = key[v];
                    u = v;
                }
            }
            mstSet[u] = true;
            for(auto it : adj[u]) {
                int v = it.first;
                int weight = it.second;
                if(mstSet[v] == false && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }
        for(int i = 1; i < N; i++) {
            cout<<parent[i]<<"->"<<i<<nl;
        }
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>>adj[V];
    for(int i = 0; i < E; i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        p->addEdge(u,v,wt,adj);
    }
    p->MSTUsingPrimsAlgorithm(V,adj);
    return 0;
}
/*
I/P:
5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
O/P:
0-1
1-2
0-3
1-4
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Optimized Approach

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
    void addEdge(int u,int v,int wt,vector<pair<int,int>>adj[]) {
        adj[u].push_back({v,wt});
        adj[v].push_back({v,wt});
    }
    void MSTUsingPrimsAlgorithm(int N,vector<pair<int,int>>adj[]) {
        vector<int>parent(N);
        vector<int>key(N);
        vector<bool>mstSet(N);
        for(int i = 0; i < N; i++) {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        key[0] = 0;
        parent[0] = -1;
        pq.push({0,0});
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            mstSet[u] = true;
            for(auto it : adj[u]) {
                int v = it.first;
                int weight = it.second;
                if(mstSet[v] == false && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v],v});
                }
            }
        }
        for(int i = 1; i < N; i++) {
            cout<<parent[i]<<"->"<<i<<nl;
        }
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>>adj[V];
    for(int i = 0; i < E; i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        p->addEdge(u,v,wt,adj);
    }
    p->MSTUsingPrimsAlgorithm(V,adj);
    return 0;
}
*/

/*   2     3
 (0)---(1)---(2)
  |    /|    /
  |  8/ |5  /7
6 |  /  |  /
  | /   | /
  |/    |/
 (3)   (4)
*/

////https://leetcode.com/problems/min-cost-to-connect-all-points/description/