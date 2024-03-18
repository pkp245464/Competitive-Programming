#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define phb push_back
#define phf push_front  
#define ppf pop_front
#define ppb pop_back
#define in insert
#define as assign  
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------///
#define I INT_MAX
void BellmanFord(int graph[][3],int V,int E,int src) {
	int dis[V];
	for(int i=0;i<V;i++) {
		dis[i]=I;
	}
	dis[src]=0;
	for(int i=0;i<V-1;i++) {
		for(int j=0;j<E;j++) {
			if(dis[graph[j][0]]!=I &&
				dis[graph[j][0]]+graph[j][2]<dis[graph[j][1]]) {
				dis[graph[j][1]]=dis[graph[j][0]]+graph[j][2];
			}
		}
	}
	for(int i=0;i<E;i++) {
		int x=graph[i][0];
		int y=graph[i][1];
		int weight=graph[i][2];
		if(dis[x]!=I && dis[x]+weight<dis[y])
			cout<<"Graph Contains Negative Weight Cycle"<<nl;
	}
	cout<<"Vertex Distance From Source"<<nl;
	for(int i=0;i<V;i++)
		cout<<"Vertex: "<<i<<" :"<<"---------->"<<"("<<dis[i]<<")"<<nl;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int V=5;
	int E=8; 
	int graph[][3]={ {0,1,-1},{0,2,4},
					 {1,2,3},{1,3,2},
					 {1,4,2},{3,2,5},
				     {3,1,1},{4,3,-3} };
	BellmanFord(graph,V,E,0);
    return 0;
}