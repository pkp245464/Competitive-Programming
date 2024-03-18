#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	//2D 
    //vector<array<int,3>>a;
    // array<int, 3>a0{{0,1,2}};
    // array<int, 3>a1{{3,4,5}};
    // array<int, 3>a2{{6,7,8}};
    // a.push_back(a0);
    // a.push_back(a1);
    // a.push_back(a2);
    
    //a.push_back({0,1,2});
    //a.push_back({3,4,5});
    //a.push_back({6,7,8});

    //for(int i = 0; i < a.size(); i++) {
    //    for(int j = 0; j < a[i].size(); j++) {
    //        cout << a[i][j] << " ";
    //    }
    //    cout << nl;
    //}
    // for(int i = 0; i < a.size(); i++) {
    //     cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << nl;
    // }
    // for(array<int, 3> i : a) {
    //     cout << i[0] << " " << i[1] << " " << i[2] << endl;
    // }
	
	
	
	//3D
	int n = 3,m = 2;
	vector<vector<array<int,3>>>graph(n);
    for(int i = 0; i < m; i++) {
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        a--,b--;
        cout << a << " " << b << " " << x << " " << y << nl;
        graph[a].push_back({b,x,y});
        graph[b].push_back({a,-x,-y});
    }
    cout << graph.size() << nl;
    for(int i = 0; i < m; i++) {
        vector<array<int,3>>temp = graph[i];
        // cout << temp.size() << " " << temp[0].size() << nl;
        cout << i << ": ";
        for(int j = 0; j < temp.size(); j++) {
            cout << temp[j][0] << " " << temp[j][1] << " " << temp[j][2] << nl;
        }
    }
	//https://atcoder.jp/contests/abc320/tasks/abc320_d
    return 0;
}