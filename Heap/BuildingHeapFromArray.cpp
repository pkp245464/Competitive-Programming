#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define phb push_back
#define phf push_front
#define ppf pop_front
#define ppb pop_back
#define in insert
#define as assign
#define nle "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
void heapify(int arr[],int n,int i) {
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=i) {
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}
void buildHeap(int arr[],int n) {
	for(int i=n/2-1;i>=0;i--) {
		heapify(arr,n,i);
	}
}
void display(int arr[],int n) {
	for(int i=0;i<n;i++)
		cout<<arr[i]<<nle;;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int arr[]{1,3,5,4,6,13,10,9,8,15,17};
	int n=sizeof(arr)/sizeof(arr[0]);
	buildHeap(arr,n);
	display(arr,n);
	return 0;
}

