//Using BFS
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
    bool checkCycle(int source,int V,vector<int>&vis,vector<int>adj[]) {
        vis[source] = true;
        queue<int>q;
        q.push(source);
        vector<int>parent(V+1,-1);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto it : adj[u]) {
                if(vis[it] == false) {
                        vis[it] = true;
                        parent[it] = u;
                        q.push(it);
                }
                else if(parent[u] != it) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V + 1,false);
        for(int i = 0; i < V; i++) {
            if(vis[i] == false) {
                if(checkCycle(i,V,vis,adj)) {
                    return true;
                }
            }
        }
        return false;
    }
    void addEdge(vector<int>adj[],int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V = 4;
    vector<int>adj[V];
    p->addEdge(adj,0,1);
    p->addEdge(adj,0,2);
    p->addEdge(adj,2,3);
    // p->addEdge(adj,2,4);
    // p->addEdge(adj,1,3);
    
    if(p->isCycle(V,adj)) {
        cout<<"YES"<<nl;
    }
    else {
        cout<<"NO"<<nl;
    }
    return 0;
}
//Or
/*
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
    bool checkForCycle(int s,int v,vector<int>adj[],vector<int>&visited) {
        queue<pair<int,int>>q;
        visited[s] = true;  
        q.push({s,-1});
        while(!q.empty()) {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto it : adj[node]) {
                if(!visited[it]) {
                    visited[it] = true;
                    q.push({it,node});
                }
                else if(par != it) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int v,vector<int>adj[]) {
        vector<int>visited(v - 1,0);
        for(int i = 1; i <= v; i++) {
            if(!visited[i]) {
                if(checkForCycle(i,v,adj,visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    void addEdge(vector<int>adj[],int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    vector<int>adj[5];
    p->addEdge(adj,0,1);
    p->addEdge(adj,0,2);
    p->addEdge(adj,2,3);
    p->addEdge(adj,1,3);
    p->addEdge(adj,2,4);
    
    if(p->isCycle(5,adj)) {
        cout<<"YES"<<nl;
    }
    else {
        cout<<"NO"<<nl;
    }
    return 0;
}
*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Using DFS

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
    bool checkForCycle(int node,int parent,vector<int>adj[],vector<int>&visited) {
        visited[node] = 1;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                if(checkForCycle(it,node,adj,visited)) {
                    return true;
                }
            }
            else if(it != parent) {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int v,vector<int>adj[]) {
        vector<int>visited(v + 1,0);
        for(int i = 0; i < v; i++) {
            if(!visited[i]) {
                if(checkForCycle(i,-1,adj,visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    void addEdge(vector<int>adj[],int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V = 5,E = 5;
    vector<int>adj[V];
    p->addEdge(adj,0,1);
    p->addEdge(adj,1,2);
    p->addEdge(adj,1,4);
    p->addEdge(adj,4,3);
    //p->addEdge(adj,2,3);
    
    if(p->isCycle(V,adj)) {
        cout<<"YES"<<nl;
    }
    else {
        cout<<"NO"<<nl;
    }
    return 0;
}
*/