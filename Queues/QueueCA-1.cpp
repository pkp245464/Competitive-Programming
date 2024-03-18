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
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
struct Queue{
	int cap,size,front;
	int *arr;
	Queue(int x) {
		cap=x;
		arr=new int[x];
		size=0;
		front=0;
	}
	bool isEmpty();
	bool isFull();
	int getFront();
	int getRear();
	void enqueue(int x);
	void dequeue();
	int getMiddle();
	void deleteMiddle();
};
bool Queue::isEmpty() {
	return (size==0);
}
bool Queue::isFull() {
	return (cap==size);
}
int Queue::getFront() {
	if(isEmpty())
		return -1;
	else
		return arr[front];
}
int Queue::getRear() {
	if(isEmpty())
		return -1;
	else
		return (front+size-1)%cap;
}
void Queue::enqueue(int x) {
	if(isFull()) {
		cout<<"Queue is Full"<<nl;
		return;
	}
	int rear=getRear();
	rear=(rear+1)%cap;
	arr[rear]=x;
	size++;
}
void Queue::dequeue() {
	if(isEmpty()) {
		return;
	}
	front=front%cap;
	int flag=arr[front];
	front++;
	size--;
}
int Queue::getMiddle() {
	if(size%2==0)
		return arr[size/2-1];
	else
		return arr[size/2];
}
void Queue::deleteMiddle() {
	if(isEmpty()) {
		return;
	}
	if(size%2==0) {
		int i=size/2-1;
		while(i<size-1) {
			arr[i]=arr[i+1];
			i++;
		}
	}
	else {
		int i=size/2;
		while(i<size-1) {
			arr[i]=arr[i+1];
			i++;
		}
	}
	size--;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	Queue q(n);
	while(n--) {
		int t;
		cin>>t;
		q.enqueue(t);
	}
	int p;
	cin>>p;
	while(p--) {
		int t;
		cin>>t;
		if(t==1) {
			int p;
			cin>>p;
			q.enqueue(p);
		}
		else if(t==2) {
			q.dequeue();
		}
		else if(t==3) {
			q.deleteMiddle();
		}
		else if(t==4) {
			cout<<q.getFront()<<nl;
		}
		else if(t==5) {
			cout<<q.getMiddle()<<nl;
		}
	}
    return 0;
}