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
//----------------------------------------------------------------------------------------------------------------///
#define V 4
#define I 99999  
void printSolution(int dist[][V]);
void floydWarshall(int graph[][V]) {
	int dist[V][V],i,j,k;
	for(i=0;i<V;i++) {
		for(j=0;j<V;j++) {
			dist[i][j]=graph[i][j];
		}
	}
	for(k=0;k<V;k++) {
		for(i=0;i<V;i++) {
			for(j=0;j<V;j++) {
				if(dist[i][j]>(dist[i][k]+dist[k][j]) &&
					(dist[k][j]!=I && dist[i][k]!=I)) {
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printSolution(dist);
}
void printSolution(int dist[][V]) {
	cout<<"Shortest Distances\nBetween Every Pair\nof Vertices\n";
	for(int i=0;i<V;i++) {
		for(int j=0;j<V;j++) {
			if(dist[i][j]==I) {
				cout<<"I"<<"   ";
			}
			else {
				cout<<dist[i][j]<<"   ";
			}
		}
		cout<<nl;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int graph[V][V]={ {0,5,I,10},
					  {I,0,3,I},
					  {I,I,0,1},
					  {I,I,I,0} };
	floydWarshall(graph);
    return 0;
}
/*          10
     (0)--------->(3)
      |            ˄
      |            |
     5|	 		   |1
      |            |
      ˅		       |
     (1)--------->(2)
             3
*/