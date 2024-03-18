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
void MaxHeapify(int arr[],int i,int n) {
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<n && arr[l]>arr[i])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=i) {
		swap(arr[i],arr[largest]);
		MaxHeapify(arr,largest,n);
	}
}
void convertMaxHeap(int arr[],int n) {
	for(int i=(n-1)/2;i>=0;--i)
		MaxHeapify(arr,i,n);

}
void display(int *arr,int size) {
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int arr[]{3,5,9,6,8,20,10,12,18,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"MinHeap Array: "<<nle;
	display(arr,n);
	convertMaxHeap(arr,n);
	cout<<"\nMaxHeap Array: "<<nle;
	display(arr,n);
	return 0;
}

