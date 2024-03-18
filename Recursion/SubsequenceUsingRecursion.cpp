#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void subSequence(int ind,vector<int>&ds,vector<int>arr) {
    if(ind == arr.size()) {
        for(auto it : ds) {
            cout << it << " ";
        }
        if(ds.size() == 0) {
            cout << "{}";
        }
        cout << nl;
        return;
    }
    ds.push_back(arr[ind]);
    subSequence(ind + 1,ds,arr);
    ds.pop_back();
    subSequence(ind + 1,ds,arr); 
}
int main(){
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n = 3,ind = 0;
    vector<int>arr{3,1,2};
    vector<int>ds;
    subSequence(ind,ds,arr); 
    return 0;
}

