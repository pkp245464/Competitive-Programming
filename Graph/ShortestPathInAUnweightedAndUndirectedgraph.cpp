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
    void BFS(int src,int n,vector<int>adj[]) {
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        vector<int>vis(n,false);
        vis[src] = true;
        queue<int>q;
        q.push(src);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto it : adj[u]) {
                if(vis[it] == false) {
                    dist[it] = dist[u] + 1;
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout<<"Distance Between Node "<<src<<" To "<<i<<": ";
            cout<<dist[i]<<nl;
        }
    }
    void addEdge(vector<int>adj[],int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V = 9;
    vector<int>adj[V];
    p->addEdge(adj,0,1);
    p->addEdge(adj,0,3);
    p->addEdge(adj,1,2);
    p->addEdge(adj,3,4);
    p->addEdge(adj,3,7);
    p->addEdge(adj,4,5);
    p->addEdge(adj,4,6);
    p->addEdge(adj,4,7);
    p->addEdge(adj,5,6);
    p->addEdge(adj,6,7);
    p->addEdge(adj,5,8);
    int source = 4;
    p->BFS(source,V,adj);
    return 0;
}

// OR

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
    void addEdge(vector<int>adj[],int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int src,int n,vector<int>adj[]) {
        vector<int>distance(n,INT_MAX);
        queue<int>q;
        distance[src] = 0;
        q.push(src);
        while(q.empty() == false) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(distance[node] + 1 < distance[it]) {
                    distance[it] = distance[node] + 1;
                    q.push(it);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout<<"Distance Between Node "<<src<<" To "<<i<<": ";
            cout<<distance[i]<<nl;
        }
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V = 9;
    vector<int>adj[V];
    p->addEdge(adj,0,1);
    p->addEdge(adj,0,3);
    p->addEdge(adj,1,2);
    p->addEdge(adj,3,4);
    p->addEdge(adj,3,7);
    p->addEdge(adj,4,5);
    p->addEdge(adj,4,6);
    p->addEdge(adj,4,7);
    p->addEdge(adj,5,6);
    p->addEdge(adj,6,7);
    p->addEdge(adj,5,8);
    int source = 4;
    p->BFS(source,V,adj);
    return 0;
}

/*
O/P:
Distance Between Node 4 To 0: 2
Distance Between Node 4 To 1: 3
Distance Between Node 4 To 2: 4
Distance Between Node 4 To 3: 1
Distance Between Node 4 To 4: 0
Distance Between Node 4 To 5: 1
Distance Between Node 4 To 6: 1
Distance Between Node 4 To 7: 1
Distance Between Node 4 To 8: 2

(1)-------(0)    (7)-----(6)
 |         |     / |     /|        
 |         |    /  |    / |       
 |         |   /   |   /  |     
 |         |  /    |  /   |        
 |         | /     | /    |                
(2)       (3)-----(4)----(5)-----(8)

*/