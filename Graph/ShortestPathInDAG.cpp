//Shortest Path in Directed Acyclic Path

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
#define INF INT_MAX
class Solution {  
public:
    void addEdge(int u,int v,int wt,vector<pair<int,int>>adj[]) {
        adj[u].push_back({v,wt});
    }
    void findTopoSort(int source,vector<int>&vis,stack<int>&s,vector<pair<int,int>>adj[]) {
        vis[source] = 1;
        for(auto it : adj[source]) {
            if(!vis[it.first]) {
                findTopoSort(it.first,vis,s,adj);
            }
        }
        s.push(source);
    }
    void shortestPath(int src,int n,vector<pair<int,int>>adj[]) {
        vector<int>vis(n,false);
        stack<int>s;
        for(int i = 0; i < n; i++) {
            if(vis[i] == false) {
                findTopoSort(i,vis,s,adj);
            }
        }
        vector<int>distance(n,1e9 + 7);
        distance[src] = 0;
        while(!s.empty()) {
            int u = s.top();
            s.pop();
            if(distance[u] != INF) {
                for(auto it : adj[u]) {
                    if(distance[it.first] > distance[u] + it.second) {
                        distance[it.first] = distance[u] + it.second;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            (distance[i] == 1e9 ) ? cout<<"INF ":cout<<distance[i]<<" "; 
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
    for(int i = 0 ; i < E; i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        p->addEdge(u,v,wt,adj);
        //Or adj[u].push_back({v,wt});
    }
    int source = 0;
    p->shortestPath(source,V,adj);
    return 0;
}

/*
I/P:-
6 7
0 1 2
0 4 1
1 2 3
4 2 2
4 5 4
2 3 6
5 3 1
O/P:- 0 2 3 6 1 5
*/