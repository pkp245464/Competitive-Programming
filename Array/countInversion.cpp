#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int merge(int left,int mid,int right,vector<int>&temp,vector<int>&arr) {    
	int i = left,j = mid,k = left,cntInversions = 0;
	while((i <= mid-1) && (j <= right)) {
		if(arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			cntInversions += (mid - i);
		}
	}
	while(i <= mid - 1) {
		temp[k++] = arr[i++];
	}
	while(j <= right) {
		temp[k++] = arr[j++];
	}
	for(i = left ; i <= right ; i++) {
		arr[i] = temp[i];
	}
	return cntInversions;
}
int mergeSort(int left,int right,vector<int>&temp,vector<int>&arr) {
	int mid,cntInversions = 0;
	if(right > left) {
		mid = left + (right - left) / 2;
		cntInversions += mergeSort(left,mid,temp,arr);
		cntInversions += mergeSort(mid+1,right,temp,arr);
		cntInversions += merge(left,mid+1,right,temp,arr);
	}
	return cntInversions;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    vector<int>arr = {1,0,1,0};
    vector<int>temp(arr.size());
    cout << mergeSort(0,arr.size() - 1,temp,arr) << nl;
    return 0;
}
