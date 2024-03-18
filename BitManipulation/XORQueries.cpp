#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
vector<int> xorQueries(vector<int>&a,vector<pair<int,int>>&queries) {
    vector<int>ans;
    for(int i = 1; i < a.size(); i++) {
        a[i] = a[i] ^ a[i - 1];
    }
    for(auto it : queries) {
        int l = it.first,r = it.second;
        if(l == 0) {
            ans.push_back(a[r]);
        }
        else {
            ans.push_back(a[l - 1] ^ a[r]);
        }
    }
    return ans;
}
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int>a = {1,3,4,8};
    vector<pair<int,int>>queries = {{0,1},{1,2},{0,3},{3,3}};
    vector<int>ans = xorQueries(a,queries);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
