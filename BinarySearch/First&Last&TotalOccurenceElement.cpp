#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long  
#define ld long double     
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int firstBS(vector<int>&nums,int target) {
    int first = -1;
    int l = 0;
    int h = nums.size()-1;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(nums[mid] == target) {
            h = mid - 1;
            first = mid;
        }
        else if(nums[mid] > target) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return first;
}
int secondBS(vector<int>&nums,int target) {
    int second = -1;
    int l = 0;
    int h = nums.size() - 1;
    while(l <= h) {
        int mid = l + (h - l) / 2;  
        if(nums[mid] == target) {
            l = mid + 1;
            second = mid;
        }
        else if(nums[mid] > target) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }  
    }
    return second;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
#endif
    vector<int>arr{5,7,7,9,9,9,10};
    int target = 9;
    cout << firstBS(arr,target) << nl; //first occurence
    cout << secondBS(arr,target) << nl; //second occurence
    int ans = secondBS(arr,target) - firstBS(arr,target); 
    cout << ans + 1 << nl; //find the total occurence of elements
    return 0;
}
