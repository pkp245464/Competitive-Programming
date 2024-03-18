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
    bool isCyclic(int V, vector<int> adj[]) {  
        queue<int>q;
        vector<int>indegree(V,0);
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it); 
                }
            }
        }
        if(cnt == V) {
            return false;
        }
        return true;
    }
    void addEdge(vector<int>adj[],int u,int v) {
        adj[u].push_back(v);
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V = 6;
    vector<int>adj[V];
    p->addEdge(adj,0,1);
    p->addEdge(adj,1,2);
    p->addEdge(adj,1,5);
    p->addEdge(adj,2,3);
    p->addEdge(adj,3,4);
    p->addEdge(adj,4,0);
    p->addEdge(adj,4,1);

    if(p->isCyclic(V,adj)) {
        cout<<"Cycle Detected"<<nl;
    }
    else {
        cout<<"No Cycle Detected"<<nl;
    }
    return 0;
}
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Detected Cycle In Directed Graph Using DFS

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
    }
    bool checkCycle(int node,vector<int>&vis,vector<int>&dfsVis,vector<int>adj[]) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it : adj[node]) {
            if(vis[it] == false) {
                if(checkCycle(it,vis,dfsVis,adj)) {
                    return true;
                }
            }
            else if(vis[it] == true && dfsVis[it] == true) {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }
    bool isCyclic(int n,vector<int>adj[]) {
        vector<int>vis(n,0);
        vector<int>dfsVis(n,0);
        for(int i = 0; i < n; i++) {
            if(vis[i] == false) {
                if(checkCycle(i,vis,dfsVis,adj)) {
                    return true;
                }
            }
        }
        return false;
    }   
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V = 6;
    vector<int>adj[V];
    p->addEdge(adj,0,1);
    p->addEdge(adj,1,2);
    p->addEdge(adj,1,5);
    p->addEdge(adj,2,3);
    p->addEdge(adj,3,4);
    p->addEdge(adj,4,0);
    p->addEdge(adj,4,1);

    if(p->isCyclic(V,adj)) {
        cout<<"Cycle Detected"<<nl;
    }
    else {
        cout<<"No Cycle Detected"<<nl;
    }
    return 0;
}
*/