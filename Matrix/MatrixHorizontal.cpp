#include<bits/stdc++.h>
using namespace std;
#define lli long long int
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
    int n = 5;
    vector<vector<int>>arr;
    for(int i = 1; i <= n; i++) {
        vector<int>temp;
        for(int j = 1; j <= n; j++) {
            temp.push_back(i + n * (j -1));
        }
        arr.push_back(temp);
    }
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<nl;
    }
    return 0;
}

/*
O/P :
1 6 11 16 21 
2 7 12 17 22 
3 8 13 18 23 
4 9 14 19 24 
5 10 15 20 25 
*/