// Given array every element frequency is three except one elmenet find that one. 
#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int uniqueNumber(vector<int>&arr) {
    int n = arr.size(),ind = 1,ans = 0;
    vector<int>cnt(32,0);
    for(int i = 0; i < n; i++) {
        int j = 0,num = arr[i];
        while(num > 0) {
            cnt[j] += (num & 1); // increment the ith postions by 1
            j++; 
            num = num >> 1;
        }
    }
    for(int i = 0; i < 32; i++) {
        cnt[i] %= 3;
        ans += cnt[i] * ind; // 2^0, 2^1,2^2,2^3,.....,2^n 
        ind = ind << 1; // 2^i -> 2^(i + 1)
    }
    return ans;
}   
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    vector<int>nums = {1,1,1,2,2,2,5,3,3,3,4,4,4};  
    cout << uniqueNumber(nums) << nl; // O/p : 5
    return 0;
}