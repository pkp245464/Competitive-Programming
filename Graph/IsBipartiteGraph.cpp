//Using BFS

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
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
    bool bipartiteBFS(int src,vector<int>&color,vector<int>adj[]) {
        queue<int>q;
        q.push(src);
        color[src] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(color[it] == -1) {
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int n,vector<int>adj[]) {
        vector<int>color(n,-1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(!bipartiteBFS(i,color,adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int m,n;
    cin>>m>>n;
    vector<int>adj[m];
    for(int i = 0; i < n; i++) {
        int u,v;
        cin>>u>>v;
        p->addEdge(adj,u,v);
    }

    if(p->isBipartite(m,adj)) {
        cout<<"YES"<<nl;
    }
    else {
        cout<<"NO"<<nl;
    }
    return 0;
}

/*

//Using DFS
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
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
    bool bipartiteDFS(int node,vector<int>&color,vector<int>adj[]) {
        if(color[node] == -1) {
            color[node] = 1;
        }
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                if(!bipartiteDFS(it,color,adj)) {
                    return false;
                }
            }
            else if(color[it] == color[node]) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int n,vector<int>adj[]) {
        vector<int>color(n,-1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                color[i] = 1;
                if(!bipartiteDFS(i,color,adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int m,n;
    cin>>m>>n;
    vector<int>adj[m];
    for(int i = 0; i < n; i++) {
        int u,v;
        cin>>u>>v;
        p->addEdge(adj,u,v);
    }
    if(p->isBipartite(m,adj)) {
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
// bipartite graph example 
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 
*/ 
/*
// not bipartite example
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
*/