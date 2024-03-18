//Kahn's Algorithms (Topological Sort Using BFS)

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
    vector<int> topologicalSort(int n,vector<int>adj[]) {
        queue<int>q;
        vector<int>indegree(n,0),ans;
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
int main(){  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int N = 6;
    vector<int>adj[N];

    p->addEdge(adj,5,2);
    p->addEdge(adj,5,0);
    p->addEdge(adj,4,0);
    p->addEdge(adj,4,1);
    p->addEdge(adj,3,1);
    p->addEdge(adj,2,3);

    vector<int>ans = p->topologicalSort(N,adj);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Topological Sort Using DFS

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
    void findTopoSort(int node,vector<int>&vis,stack<int>&s,vector<int>adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                findTopoSort(it,vis,s,adj);
            }
        } 
        s.push(node);
    }
    vector<int> topologicalSort(int n,vector<int>adj[]) {
        stack<int>s;  
        vector<int>vis(n,0);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                findTopoSort(i,vis,s,adj);
            }
        }
        vector<int>ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int N = 6;
    vector<int>adj[N];

    p->addEdge(adj,5,2);
    p->addEdge(adj,5,0);
    p->addEdge(adj,4,0);
    p->addEdge(adj,4,1);
    p->addEdge(adj,2,3);
    p->addEdge(adj,3,1);

    vector<int>ans = p->topologicalSort(N,adj);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
*/