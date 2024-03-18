/*
Q.1)You are given an array of n integers, and your task is to find three values (at distinct positions)
	whose sum is x.
I/P:
n = 4,sum = 8;
a[n] = {2,7,5,1}
O/P: 1 3 4 
*/

//TC - O(n^2)
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
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
    int n,sum;
    cin >> n >> sum;
    vector<pair<int,int>>vp(n);
    for(int i = 0; i < n; i++) {
        cin >> vp[i].first;
        vp[i].second = i + 1;
    }  
    sort(vp.begin(),vp.end());  
    for(int i = 0; i < n; i++) {
        int l = 0,r = n - 1;
        while(l != r) {
            int tar = sum - vp[i].first;
            if(i != l && i != r && vp[l].first + vp[r].first == tar) {
                cout << vp[i].second << " " << vp[l].second << " " << vp[r].second << nl;
                return 0;
            }
            if(vp[l].first + vp[r].first < tar) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << nl;
    return 0;
}

/*
Q.2)You are given an array of n integers, and your task is to find four values (at distinct positions)
	whose sum is x. 
I/P:
n = 8,sum = 15;
a[n] = {3,2,5,8,1,3,2,3};
O/P: 4 7 2 1

//TC: O(n^2logn)
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
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
    int n,sum;
    cin >> n >> sum;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }  
    map<int,pair<int,int>>m;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int tar = sum - a[i] - a[j];
            if(m.count(tar)) {
                cout << i + 1 << " " << j + 1 << " " << m[tar].first + 1 << " " << m[tar].second + 1 << nl;
                return 0;
            }
        }
        for(int j = 0; j < i; j++) {
            m[a[i] + a[j]] = {i,j};
        }
    }
    cout << "IMPOSSIBLE" << nl;
    return 0;
}
*/