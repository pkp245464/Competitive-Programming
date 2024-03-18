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
    int m,n;
    cin>>m>>n;
    vector<int>arr(m),nums(n),ans(m + n);
    for(int i = 0; i < m; i++) {
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    int i = 0,j = 0;
    while(i < m || j < n) {
        if(i == arr.size() || j < n && arr[i] > nums[j]) {
            ans[i + j] = nums[j];
            j++;
        }
        else {
            ans[i + j] = arr[i];
            i++;
        }
    }
    for(int i = 0; i < m + n; i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}


//Or

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
    int m,n;
    cin>>m>>n;
    vector<int>arr(m),nums(n),ans(m + n);
    for(int i = 0; i < m; i++) {
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    arr.push_back(INT_MAX);
    nums.push_back(INT_MAX);
    int i = 0,j = 0;
    while(i < m || j < n) {
        if(arr[i] > nums[j]) {
            ans[i + j] = nums[j];
            j++;
        }
        else {
            ans[i + j] = arr[i];
            i++;
        }
    }
    for(int i = 0; i < m + n; i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}


