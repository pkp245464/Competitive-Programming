// BFS For Multiple Graph(Component)
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
	vector<int> bfsOfGraph(int v,int source,vector<int>adj[])  {
		vector<int>ans;
		vector<int>vis(v+1,0);
		queue<int>q;
		q.push(source);
		vis[source] = 1;  
		while(!q.empty()) {
			int val = q.front();
			q.pop();
			ans.push_back(val);
			for(auto it : adj[val]) {
				if(!vis[it]) {  //if(vis[it] == 0)
					q.push(it);
					vis[it] = 1;
				}
			}
		}
		return ans;
	}
};
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	Solution *p = new Solution();
	int t;
	cin>>t;
	while(t--) {
		int V,E;  //node and vertex is same things
		cin>>V>>E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int source = 2;
		vector<int>ans = p->bfsOfGraph(V,source,adj);
		for(int i = 0; i < ans.size(); i++) {
			cout<<ans[i]<<" ";
		} 
		cout<<nl;
	}
 	return 0;
}

/*
1
4 4
0 1 
0 3
1 2
2 3
O/P- 0 1 3 2 
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//DFS For Multiple Graph(Component)

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
	void dfs(int source,vector<int>&vis,vector<int>adj[],vector<int>&ans) {
		ans.push_back(source);		
		vis[source] = true;
		for(auto it : adj[source]) {
			if(vis[it] == 0) {
				dfs(it,vis,adj,ans);
			}
		}
	}
	vector<int> dfsOfGraph(int v, vector<int>adj[]) {
		vector<int>ans;
		vector<int>vis(v+1,false);
		for(int i = 0; i < v; i++) {
			if(vis[i] == false) {
				dfs(i,vis,adj,ans);
			}
		}
		return ans;
	}
};
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--) {
		int V,E;
		cin>>V>>E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution *p = new Solution();
		vector<int>ans = p->dfsOfGraph(V,adj);
		for(int i = 0; i < ans.size(); i++) {
			cout<<ans[i]<<" ";
		} 
		cout<<nl;
	}
 	return 0;
}

I/P:
1
4 4
0 1 
0 3
1 2
2 3
O/P - 0 1 2 3 
*/