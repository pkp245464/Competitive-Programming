#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Node {
public:   
    int u,v,wt;
    Node(int first,int second,int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
class Solution {
public:
    static bool comparator(Node a,Node b) {
        return a.wt < b.wt;
    }
    int find(int u,vector<int>&parent) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u],parent);
    }
    void Union(int u,int v,vector<int>&parent,vector<int>&rank) {
        u = find(u,parent);
        v = find(v,parent);
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    int V,E;
    cin>>V>>E;
    vector<Node>edges;   
    for(int i = 0; i < E; i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(Node(u,v,wt));
    }
    sort(edges.begin(),edges.end(),p->comparator);

    vector<int>parent(V);
    for(int i = 0; i < V; i++) {
        parent[i] = i;
    }
    vector<int>rank(V,0);
    int cost = 0;
    vector<pair<int,int>>MST;
    for(auto it : edges) {
        if(p->find(it.u,parent) != p->find(it.v,parent)) {
            cost += it.wt;
            MST.push_back({it.u,it.v});
            p->Union(it.u,it.v,parent,rank);
        }
    }
    cout<<"Cost: "<<cost<<nl;
    for(int i = 0; i < MST.size(); i++) {
        cout<<MST[i].first<<"->"<<MST[i].second<<nl;
    }
    return 0;
}
/*
I/P:
5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
Or
5 12
0 1 2
0 3 6
1 0 2
1 2 3
1 3 8
1 4 5
2 1 3
2 4 7
3 0 6
3 1 8
4 1 5
4 2 7
O/P:
Cost: 16
0->1
1->2
1->4
0->3
*/

/*   2     3
 (0)---(1)---(2)
  |    /|    /
  |  8/ |5  /7
6 |  /  |  /
  | /   | /
  |/    |/
 (3)   (4)
*/

    