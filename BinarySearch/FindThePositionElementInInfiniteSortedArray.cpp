#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double   
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int binarySearch(int l,int h,vector<int>&nums,int target) {
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
int infiniteSearchInSortedArray(vector<int>&nums,int key) {
	int l = 0,h = 1,val = nums[l];
	while(key > val) {
		l = h;
		h = 2 * h;
		val = nums[h];
	}
	return binarySearch(l,h,nums,key);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr{3,9,10,20,25,27,30,40,50,55,60,70,80,81,90};
    //Make inifnite size Array for working proper
    for(int i = 0; i < 100; i++) {
        arr.push_back(1000 + i);
    }
    int target = 90;
    cout << infiniteSearchInSortedArray(arr,target) << nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/


/*

//Index of First 1 in a Binary Sorted Infinite Array

 
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double   
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int firstBS(int l,int h,vector<int>&nums) {
	int first = -1;
	while(l <= h) {
		int mid = l + (h - l) / 2;
		if(nums[mid] == 1) {
			h = mid - 1;
			first = mid;
		}
		else if(nums[mid] > 1) {
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return first;
}
int infiniteSearchInSortedArray(vector<int>&nums) {
	int l = 0,h = 1;
	while(nums[h] == 0) {
		l = h;
		h = 2 * h;
	}
	return firstBS(l,h,nums);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr{0,0,0,0,0,0,0,0,0,1,1,1,1,1};
    //Make inifnite size Array for working proper
    for(int i = 0; i < 100; i++) {
        arr.push_back(1);
    }
    cout << infiniteSearchInSortedArray(arr) << nl;
    return 0;
}
*/