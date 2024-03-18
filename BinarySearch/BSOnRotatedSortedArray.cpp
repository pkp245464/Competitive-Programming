#include "bits/stdc++.h"
using namespace std;  
#define ll long long 
#define llu unsigned long long int
#define ld long double  
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int findTheMinimumElement(vector<int>&nums) {
    int n = nums.size();
    int l = 0;  
    int h = n - 1;
    if(n == 1) return nums[0];
    while(l <= h) {
        int mid = l + (h - l) / 2;
		//to avoid array index of bounds we used module for finding the prev and next
        int prev = (mid + n -1 ) % n; //prev = mid - 1 :without modulo
        int next = (mid + 1) % n; //next = mid + 1 :without modulo
        if(nums[mid] < nums[prev] && nums[mid] < nums[next]) { // minimum element is less than both neighbour
            return mid; 
        }
        else if(nums[h] < nums[mid]) {
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return -1;
}
//Normal BS
int findElement(int l,int h,vector<int>&nums,int target) {
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(target > nums[mid]) {
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return -1;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    vector<int>arr{6,7,8,9,1,2,3,4,5};
    int target = 5;
    int pivot = findTheMinimumElement(arr);
    cout << pivot << nl;
    if(target >= arr[0]) {
        cout << findElement(0,pivot - 1,arr,target) << nl;
    }
    else {
        cout<< findElement(pivot,arr.size() - 1,arr,target) << nl;    
    }
	//P-for finding the number of times array rotated
	//A-if you find the minimum element index is same as number of times array rotated
    return 0;
}