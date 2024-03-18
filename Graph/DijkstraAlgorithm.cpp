#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void addEdge(int u,int v,int wt,vector<pair<int,int>>adj[]) {
	adj[u].push_back({v,wt});
}
void dijkstraAlgorithm(int src,int V,vector<pair<int,int>>adj[]) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<int>distance(V + 1,INT_MAX);
	   
	distance[src] = 0;
	pq.push(make_pair(0,src));

	while(!pq.empty()) {
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		for(auto it = adj[prev].begin(); it != adj[prev].end(); it++) {
			int next = it->first;  
			int nextDist = it->second;
			if(distance[next] > distance[prev] + nextDist) {
				distance[next] = distance[prev] + nextDist;
				pq.push(make_pair(distance[next],next));
			}
		}
	}
	cout<<"The Distance From Soure "<<src<<" are: \n";
	for(int i = 1; i <= V; i++) {
		cout<<distance[i]<<" ";
	}
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>>adj[V + 1];
    for(int i = 0; i < E; i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        p->addEdge(u,v,wt,adj);
    }
    int source = 1;
    dijkstraAlgorithm(source,V,adj);
    return 0;
}

/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/