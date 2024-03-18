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
	int front,rear,size,capacity;
	int *array;
};
Queue *create(int capacity) {
	Queue *queue=new Queue();
	queue->capacity=capacity;
	queue->front=queue->size=0;
	queue->rear=capacity-1;
	queue->array=new int[queue->capacity];
	return queue;
}
int isFull(Queue *queue) {
	return (queue->size==queue->capacity);
}
int isEmpty(Queue *queue) {
	return (queue->size==0);
}
void enqueue(Queue *queue,int item) {
	if(isFull(queue))
		return;
	queue->rear=(queue->rear+1)%queue->capacity;
	queue->array[queue->rear]=item;
	queue->size=queue->size+1;
	cout<<"Enqueued : "<<item<<"\n";
}
int dequeue(Queue *queue) {
	if(isEmpty(queue))
		return INT_MIN;
	int item=queue->array[queue->front];
	queue->front=(queue->front+1)%queue->capacity;
	queue->size=queue->size-1;
	return item;
}
int front(Queue *queue) {
	if(isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}
int rear(Queue *queue) {
	if(isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Queue *queue=create(100);
	enqueue(queue,10);
	enqueue(queue,20);
	enqueue(queue,30);
	enqueue(queue,40);
	enqueue(queue,50);
	cout<<"Dequeue : "<<dequeue(queue)<<"\n";
	cout<<"Front item: "<<front(queue)<<"\n";
	cout<<"Rear item: "<<front(queue)<<"\n";	
    return 0;
}