//Union by Rank without class

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int n = 1000000;
int parent[n];
int ranK[n];
void makeSet() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        ranK[i] = 0;
    }
}
int findParent(int node) {
    if(node == parent[node]) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}
void unionByRank(int u,int v) {
    u = findParent(u);
    v = findParent(v);
    if(ranK[u] < ranK[v]) {
        parent[u] = v;
    }
    else if(ranK[v] < ranK[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        ranK[u]++;
    }
} 
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    makeSet();
    int m;
    cin >> m;
    while(m--) {
        int u,v;
        cin >> u >> v;
        unionByRank(u,v);
    }
    if(findParent(2) != findParent(7)) cout << "Different Set" << nl;
    else cout << "Same Set" << nl;
    return 0;
}
/*
7
1 2
2 3
4 5
6 7
5 6

3 7

*/

/*
//Union by rank and size both implementation
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class DSU {
    vector<int>rank,parent,size; 
public: 
    DSU(int n) {
        rank.resize(n + 1, 0); 
        parent.resize(n + 1);
        size.resize(n + 1); 
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }
	//findSet - returns the representative (also ultimate parent) of the set that contains the element v
    //without path compression
    // int findSet(int v) { //finding ultimate parent
    //     if(v == parent[v]) {
    //         return v;
    //     }
    //     return findSet(parent[v]);
    // }
    //with Path Compression
    int findSet(int v) {
        if(v == parent[v]) {
            return v; 
        }
        return parent[v] = findSet(parent[v]); 
    }
    void unionByRank(int u, int v) {
        int a = findSet(u); // finding the ultimate parent of u
        int b = findSet(v); // finding the ultimate parent of v
        if(a == b) return; 
        if(rank[a] < rank[b]) {
            parent[a] = b; 
        }
        else if(rank[b] < rank[a]) {
            parent[b] = a; 
        }
        else {
            parent[b] = a; 
            rank[a]++; 
        }
    }
    void unionBySize(int u, int v) {
        int a = findSet(u); 
        int b = findSet(v); 
        if(a == b) return; 
        if(size[a] < size[b]) {
            parent[a] = b; 
            size[b] += size[a]; 
        }
        else {
            parent[b] = a;
            size[a] += size[b]; 
        }
    }
	//get Size by Union By Size(not valid for union By Rank)
	int getSizeUBySize(int x) { // use for only unionBySize method
    	return size[findSet(x)];
    }
};
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    DSU ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 

	// if two elements are part of the same set or not
    // if 3 and 7 same or not 
    if(ds.findSet(3) == ds.findSet(7)) cout << "Same" << nl; //
    else cout << "Not same" << nl; 

    ds.unionBySize(3, 7); 

    if(ds.findSet(3) == ds.findSet(7)) cout << "Same" << nl; 
    else cout << "Not same" << nl; 
    
    return 0;
}