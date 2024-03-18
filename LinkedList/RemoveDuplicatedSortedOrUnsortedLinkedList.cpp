//Remove Duplicate from Unsorted Linked List
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Node {
public:
	int data;
	Node *next;
};
void removeDuplicate(Node *start) {
	unordered_set<int>s;
	Node *cur=start;
	Node *prev=NULL;
	while(cur!=NULL) {
		if(s.find(cur->data)!=s.end()) {
			prev->next=cur->next;
			delete(cur);
		}
		else {
			s.insert(cur->data);
			prev=cur;
		}
		cur=prev->next;
	}
}
void push(Node **head,int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->next=(*head);
	(*head)=newNode;
}
void display(Node *head) {
	if(head==NULL) return;
	cout<<head->data<<" ";
	display(head->next);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *head=NULL;
	push(&head,50);
	push(&head,40);	
	push(&head,30);
	push(&head,20);
	push(&head,20);
	push(&head,40);
	push(&head,50);
	removeDuplicate(head);
	display(head);
    return 0;
}
/*
Remove Duplicate from Sorted Linked List

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Node {
public:
	int data;
	Node *next;
};
void removeDuplicate(Node *head) {
	Node *cur=head;
	Node *nextPointer;
	if(cur==NULL) {
		return;
	}
	while(cur->next!=NULL) {
		if(cur->data==cur->next->data) {
			nextPointer=cur->next->next;
			delete(cur->next);
			cur->next=nextPointer;
		}
		else {
			cur=cur->next;
		}
	}
}
void push(Node **head,int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->next=(*head);
	(*head)=newNode;
}
void display(Node *head) {
	if(head==NULL) return;
	cout<<head->data<<" ";
	display(head->next);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *head=NULL;
	push(&head,60);
	push(&head,60);
	push(&head,50);
	push(&head,40);	
	push(&head,30);
	push(&head,20);
	push(&head,10);
	removeDuplicate(head);
	display(head);
    return 0;
}
*/

