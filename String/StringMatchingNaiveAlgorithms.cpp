#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
vector<int> searchPattern(string &t,string &p) {
    int n = t.size(),m = p.size();
    vector<int>index;
    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; ++j) {
            if(p[j] != t[i + j]) {
                break;
            }
        }
        if(j == m) {
            index.push_back(i);
        }
    }
    return index;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string t = "pankajpankajpankaj";
    string p = "ank";
    vector<int>index = searchPattern(t,p);
    for(int i = 0; i < index.size(); i++) {
        cout << index[i] << " ";
    }
    return 0;
}