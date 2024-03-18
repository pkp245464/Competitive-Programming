//Time Complexity O(n^2)
//Space Complexity O(1)
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void maxWater(vector<int>&arr) {
	int n=arr.size();
	int res=0;
	for(int i=1;i<n-1;i++) {
		int left=arr[i];
		for(int j=0;j<i;j++) {
			left=max(left,arr[j]);
		}
		int right=arr[i];
		for(int j=i+1;j<n;j++) {
			right=max(right,arr[j]);
		}
		res+=min(left,right)-arr[i];
	}
	cout<<res<<nl;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
	vector<int>arr{2,0,3,0,1,0,2};
	maxWater(arr);
    return 0;
}
//--------------------------------------------------------------------------//	
//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
//Time Complexity O(n)
//Space Complexity O(n)
/*
void totalWater(int arr[],int n) {
	int left[n],right[n],water=0;
	
	left[0]=arr[0];
	for(int i=1;i<n;i++)
		left[i]=max(left[i-1],arr[i]);
	
	right[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
		right[i]=max(right[i+1],arr[i]);

	for(int i=0;i<n;i++)
		water+=min(left[i],right[i])-arr[i];
	cout<<water<<"\n";
}
*/
//--------------------------------------------------------------------------//	
//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
//Or  best Solution
//Time Complexity O(n)
//Space Complexity O(1)
/*
void maxWater(vector<int>&arr) {
	int ans=0;
	int maxLeft=0,maxRight=0;
	int low=0,high=arr.size()-1;
	while(low<=high) {
		if(arr[low]<arr[high]) {
			if(arr[low]>maxLeft) {
				maxLeft=arr[low];
			}
			else {
				ans+=maxLeft-arr[low];
			}
			low++;
		}
		else {
			if(arr[high]>maxRight) {
				maxRight=arr[high];
			}
			else {
				ans+=maxRight-arr[high];
			}
			high--;
		}
	}
	cout<<ans<<nl;
}
*/
/*
Trapping Rain Water Problem
Array{2,0,1,0,3,3,2,3,0,3,1,0,2}
 _________________________________________
|             __ __    __    __           |
| __         |__|__|__|__|  |__|      __  |
||__|   __   |__|__|__|__|  |__|   __|__| |
||__|__|__|__|__|__|__|__|__|__|__|__|__| | 
|__2__0__1__0__3__3__2__3__0__3__0__1__2__|
|_________________________________________|
Ans:->12
*/