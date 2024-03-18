#include "bits/stdc++.h"
using namespace std;
#define ll long long   
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int floorInSortedArray(vector<int>&nums,int target) {
    int l = 0,h = nums.size()-1,ans = -1;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(target == nums[mid]) {
            return nums[mid];
        }
        else if(target < nums[mid]) {
            h = mid - 1;
        }
        else {
            ans = nums[mid];
            l = mid + 1;
        }
    }
    return ans;
} 
int ceilInSortedArray(vector<int>&nums,int target) {
    int l = 0,h = nums.size()-1,ans = -1;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(target == nums[mid]) {
            return nums[mid];
        }
        else if(target < nums[mid]) {
            ans = nums[mid];
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}
char nextGreaterCharacter(vector<char>&nums,char target) {
    int l = 0;
    int h = nums.size() - 1;
    char ans = '0';
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(target == nums[mid]) {
            l = mid + 1;
        }
        else if(target < nums[mid]) {
            ans = nums[mid];
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    vector<int>arr{10,20,30,40,50,60,70,80,90};
    int target1 = 91;
    cout << floorInSortedArray(arr,target1) << nl;
    cout << ceilInSortedArray(arr,target1) << nl;

    vector<char>vc{'A','B','C','C','E','E','F','G','H','I'};
    char target2 = 'E'; //O/P: F
    char target3 = 'Z'; //O/P: E
    char target4 = 'J'; //O/P: 0
    cout << nextGreaterCharacter(vc,target4) << nl;

    return 0;
}
/*
Case1-Target: 80
Floor: 80
Ceil: 80

Case2-Target: 85
Floor: 80
Ceil: 90

Case3-Target: 9
Floor: -1
Ceil: 10

Case4-Target: 91
Floor: 90
Ceil: -1
*/