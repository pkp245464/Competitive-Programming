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
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
class Queue {
public:
	int rear,front,size,*arr;
	Queue(int s) {
		front=rear=-1;
		size=s;
		arr=new int[s];
	}
	void enQueue(int value);
	int deQueue();
	void displayQueue();
};
void Queue::enQueue(int value) {
	if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))) {
		cout<<"Queue is Full"<<"\n";
		return;
	}
	else if(front==-1) {
		front=rear=0;
		arr[rear]=value;
	}
	else if(rear==size-1 && front!=0) {
		rear=0;
		arr[rear]=value;
	}
	else {
		rear++;
		arr[rear]=value;
	}
}
int Queue::deQueue() {
	if(front==-1) {
		cout<<"Queue is Empty"<<"\n";
		return INT_MIN;
	}
	int data=arr[front];
	arr[front]=-1;
	if(front==rear) {
		front=-1;
		rear=-1;
	}
	else if(front==size-1)
		front=0;
	else
		front++;
	return data;
}
void Queue::displayQueue() {
	if(front==-1) {
		cout<<"Queue is Empty"<<"\n";
		return;
	}
	cout<<"Elements in Circular Queue are: ";
	if(rear>=front) {
		for(int i=front;i<=rear;i++)
			cout<<arr[i]<<" ";
	}
	else {
		for(int i=front;i<size;i++)
			cout<<arr[i]<<" ";
		for(int i=0;i<=rear;i++)
			cout<<arr[i]<<"";
	}
	cout<<"\n";
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    Queue q(5);
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
    q.displayQueue();
    cout<<"Deleted value="<<q.deQueue()<<"\n";
    cout<<"Deleted value="<<q.deQueue()<<"\n";
    q.displayQueue();
    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);
    q.displayQueue();
    q.enQueue(20);
    return 0;
}