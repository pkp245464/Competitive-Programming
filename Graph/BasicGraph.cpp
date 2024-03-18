// Directed Graph

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
	int n,m;
	cin>>n>>m;   
	vector<int>adj[n + 1];
	for(int i = 0; i < m; i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
 	return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Undirected Graph

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector<int>adj[n + 1];
	for(int i = 0; i < m; i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 	return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// weighted Graph
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>adj[n + 1];
	for(int i = 0; i < m; i++) {
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
 	return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
//Directed Graph
// void addEdge(vector<int>adj[],int u,int v) {                
// 	adj[u].push_back(v);                                                                                                           
// } 

//Undirected Graph
void addEdge(vector<int>adj[],int u,int v) {                // [0]->[1]->[4]
	adj[u].push_back(v);                                    // [1]->[0]->[2]->[3]->[4]             
	adj[v].push_back(u);                                    // [4]->[0]->[1]->[3]                        
}                                                           // [2]->[1]->[3]              
void display(vector<int>adj[],int v) {                      // [3]->[1]->[2]->[4]       
	for(int i = 0; i < v; i++) {                                               
		cout<<"Adjacency list of vertex: "<<i<<"\nhead";          
		for(auto x : adj[i]) {                                         
			cout<<"->"<<x;                                                  
		}                                                                           
		cout<<nl;                                                        
	}
}
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int v=5;
	vector<int>adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,4);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
	addEdge(adj,3,4);
	display(adj,v);
 	return 0;
}
*/








