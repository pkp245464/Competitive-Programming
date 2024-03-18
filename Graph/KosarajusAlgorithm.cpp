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
    void addEdge(int u,int v,vector<int>adj[]) {
        adj[u].push_back(v);
    }
    void DFS(int node,vector<int>&vis,stack<int>&s,vector<int>adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                DFS(it,vis,s,adj);
            }
        }
        s.push(node);
    }
    void revDFS(int node,vector<int>&vis,vector<int>transpose[]) {
        cout<<node<<" ";
        vis[node] = 1;
        for(auto it : transpose[node]) {
            if(!vis[it]) {
                revDFS(it,vis,transpose);
            }
        }
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V = 6,E = 7;
    vector<int>adj[V + 1];
    p->addEdge(1,3,adj);
    p->addEdge(2,1,adj);
    p->addEdge(3,2,adj);
    p->addEdge(3,5,adj);
    p->addEdge(4,6,adj);
    p->addEdge(5,4,adj);
    p->addEdge(6,5,adj);
    
    stack<int>s;
    vector<int>vis(V + 1,0);
    for(int i = 1; i <= V; i++) {
        if(!vis[i]) {
            p->DFS(i,vis,s,adj);
        }
    }
    
    vector<int>transpose[V + 1];
    for(int i = 1; i <= V; i++) {
        vis[i] = 0;
        for(auto it : adj[i]) {
            transpose[it].push_back(i);
        }
    }

    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(!vis[node]) {
            cout<<"SCC: ";
            p->revDFS(node,vis,transpose);
            cout<<nl;
        }
    }
    return 0;
}