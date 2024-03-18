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
        adj[v].push_back(u);
    }
	void DFS(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,int &timer,vector<int>adj[]) {
		vis[node] = 1;
		tin[node] = low[node] = timer++;
		for(auto it : adj[node]) {
			if(it == parent) {
				continue;
			}
			if(!vis[it]) {
				DFS(it,node,vis,tin,low,timer,adj);
				low[node] = min(low[node],low[it]);
				if(low[it] > tin[node]) {
					cout<<node<<" "<<it<<nl;
				}
			}
			else {
				low[node] = min(low[node],tin[it]);
			}
		}
	}
};
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	Solution *p = new Solution();
	int V,E;
	cin>>V>>E;
	vector<int>adj[V];
	for(int i = 0; i < E; i++) {
		int u,v;
		cin>>u>>v;
		p->addEdge(u,v,adj);
	}
	vector<int>tin(V,-1);
	vector<int>low(V,-1);
	vector<int>vis(V,0);
	int timer = 0;
	for(int i = 0; i < V; i++) {
		if(!vis[i]) {
			p->DFS(i,-1,vis,tin,low,timer,adj);
		}
	}
 	return 0;
}
/*
I/P:
5 5
1 0
0 2
2 1
0 3
3 4
O/P:
3 4
0 3

(1)---(0)---(3)
 |    /      |
 |   /       | 
 |  /        | 
 | /         |
(2)         (4) 

*/

/*
I/P:
7 8
0 1
0 2
2 1
1 6
1 3
1 4
3 5
4 5
O/P:
1 6

(0)     (3)
 | \    / \
 |  \  /   \
 |  (1)    (5)
 |  /| \   /
 | / |  \ /
(2) (6) (4)

*/
