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
class MinHeap {
	int *harr;
	int capacity;
	int size;
public:
	MinHeap(int capacity);
	int parent(int i) {
		return (i-1)/2;
	}
	int left(int i) {
		return (2*i+1);
	}
	int right(int i) {
		return (2*i+2);
	}
	void MinHeapify(int);
	void insertKey(int k);
	void display(int k,int pos);
};
MinHeap::MinHeap(int cap) {
	size=0;
	capacity=cap;
	harr=new int[cap];
}
void MinHeap::insertKey(int k) {
	if(size==capacity) {
		cout<<"Overflow"<<nle;
		return;
	}
	size++;
	int i=size-1;
	harr[i]=k;
	while(i!=0 && harr[parent(i)]>harr[i]) {
		swap(harr[i],harr[parent(i)]);
		i=parent(i);
	}
}
void MinHeap::MinHeapify(int i) {
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<size && harr[l]<harr[i])
		smallest=l;
	if(r<size && harr[r]<harr[smallest])
		smallest=r;
	if(smallest!=i) {
		swap(harr[i],harr[smallest]);
		MinHeapify(smallest);
	}
}
void MinHeap::display(int x,int pos=0) {
	if(pos>=size)
		return;
	if(harr[pos]>=x) return;
	cout<<harr[pos]<<" ";
	display(x,left(pos));
	display(x,right(pos));
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	MinHeap h(50);
	h.insertKey(3);
	h.insertKey(2);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	h.insertKey(80);
	h.insertKey(6);
	h.insertKey(150);
	h.insertKey(77);
	h.insertKey(120);
	int x=81;
	h.display(x);
	return 0;
}

