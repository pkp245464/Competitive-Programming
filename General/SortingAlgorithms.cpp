//Merge Sort Using Iterative & Recursive Method
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class MergeSort {
public:
    void merge(int low,int mid,int high,vector<int>&arr) {
        vector<int>temp;
        int left = low,right = mid + 1;
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        // if left-half element is still left
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        // if right-half element is still left
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        // copy the temp elements into the arr
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    void fun(int low,int high,vector<int>&arr) {
        if(low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        fun(low,mid,arr); // left half
        fun(mid + 1,high,arr); // right half
        merge(low,mid,high,arr);
    }   
};
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    MergeSort *p = new MergeSort();
    vector<int>arr = {9,4,5,3,8,2,1,6,7};
    int low = 0,high = arr.size() - 1;
    p->fun(low,high,arr);
    for(int i = low; i <= high ; i++) {
        cout << arr[i] << " \n"[i == high];
    }
    return 0;
}
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*
//Time Complexity-> O(n^2)
//Stable,Adapative we make using flag
void bubbleSort(vector<int>&nums) {
	int n=nums.size();
	for(int i=0;i<n-1;i++) {
		bool flag=false;
		for(int j=0;j<n-i-1;j++) {
			if(nums[j]>nums[j+1]) {
				swap(nums[j],nums[j+1]);
				flag=true;
			}
		}	
		if(flag==false) {
			break;
		}
	}
	for(int i=0;i<nums.size();i++) {
		cout<<nums[i]<<" ";
	}
}
*/
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*
//Time Complexity-> O(n^2)
//Stable,Adapative by default
void insertionSort(vector<int>&nums) {
	int n=nums.size();
	for(int i=1;i<n;i++) {
		int j=i-1;
		int r=nums[i];
		while(j>-1 && nums[j]>r) {
			nums[j+1]=nums[j];
			j--;	
		}
		nums[j+1]=r;
	}
	for(int i=0;i<n;i++) {
		cout<<nums[i]<<" ";
	}
}
*/
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*
//Time Complexity-> O(n^2)
//Not Stable,Not Adapative
void selectionSort(vector<int>&nums) {
	int n=nums.size();
	for(int i=0;i<n-1;i++) {
		int j,k;
		for(j=k=i;j<n;j++) {
			if(nums[j]<nums[k]) {
				k=j;
			}
		}
		swap(nums[i],nums[k]);
	}
	for(int i=0;i<n;i++) {
		cout<<nums[i]<<" ";
	}
}
*/
/*
Adapative Means -> if array is already sorted then it 
run only one time time not for n times.
because it recognition it is sorted.

Stable Meaans-> nums[]{50,10,40,60,20,50,70}  it means if we sort the array then their
is two element are same  { 50->index(0), 50->index(5) } after sorting index(0) 
come first,after then index(5) come second.
O/P-> {10,20,40,50(index-0),50(index-5),60,70}   -->Stable sorting
O/P-> {10,20,40,50(index-5),50(index-0),60,70}   -->Not Stable sorting
*/



/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Shell Sort 
void shellSort(vector<int>&nums) {
	int gap,i,j,temp;
	int n=nums.size();
	for(gap=n/2;gap>=1;gap=gap/2) {
		for(i=gap;i<n;i++) {
			temp=nums[i];
			j=i-gap;
			while(j>=0 && nums[j]>temp) {
				nums[j+gap]=nums[j];
				j=j-gap;
			}
			nums[j+gap]=temp;
		}
	}
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/


/*
//RadixSort

#include "bits/stdc++.h"
using namespace std;
#define nl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define imax INT_MAX
#define imin INT_MIN
const ll mod = 998244353;
const ll MOD = 1'000'000'000 + 7;
#define PI 3.1415926535897932384626433832795
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//------------------------------------------------------------------/// 
void countSort(int pos,vector<int>&a) {
	int n = a.size();
	vector<int>cnt(10);
	for(int i = 0; i < 10; i++) {
		cnt[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		cnt[(a[i] / pos) % 10]++;
	}
	for(int i = 1; i < 10; i++) {
		cnt[i] = cnt[i - 1] + cnt[i];
	}
	vector<int>ans(n);
	for(int i = n - 1; i >= 0; i--) {
		ans[cnt[(a[i] / pos) % 10] - 1] = a[i];
		cnt[(a[i] / pos) % 10]--;
	}
	for(int i = 0; i < n; i++) {
		a[i] = ans[i];
	}
}
void radixSort(vector<int>&a) {
	int maxi = *max_element(a.begin(),a.end());
	for(int pos = 1; maxi / pos > 0; pos *= 10) {
		countSort(pos,a);
	}
	for(int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>a = {237,146,259,348,152,163,235,48,36,62};
	radixSort(a);
    return 0;
}


*/