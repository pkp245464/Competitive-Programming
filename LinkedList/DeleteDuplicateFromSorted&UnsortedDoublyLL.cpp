//Delete All duplicate element from Unsorted Doubly Linked List
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
	Node *prev;
};
void push(Node **head,int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=(*head);
	if((*head)!=NULL) {
		(*head)->prev=newNode;
	}
	(*head)=newNode;
}
void display(Node *head) {
	while(head!=NULL) {
		cout<<head->data<<" ";
		head=head->next;
	}
}
void deleteNode(Node **head,Node *del) {
	if((*head)==NULL || del==NULL) {
		return;
	}
	if((*head)==del) {
		(*head)=del->next;
	}
	if(del->next!=NULL) {
		del->next->prev=del->prev;
	}
	if(del->prev!=NULL) {
		del->prev->next=del->next;
	}
	delete(del);
	return;
}
void removeDuplicate(Node **head) {
	if((*head)==NULL || (*head)->next==NULL) {
		return;
	}
	Node *ptr1,*ptr2;
	for(ptr1=(*head);ptr1!=NULL;ptr1=ptr1->next) {
		ptr2=ptr1->next;
		while(ptr2!=NULL) {
			if(ptr1->data==ptr2->data) {
				Node *next=ptr2->next;
				deleteNode(head,ptr2);
				ptr2=next;
			}
			else {
				ptr2=ptr2->next;
			}
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *head=NULL;
	push(&head,70);
	push(&head,20);
	push(&head,30);
	push(&head,40);
	push(&head,40);
	push(&head,50);
	push(&head,60);
	push(&head,20);
	push(&head,60);
	push(&head,70);
	removeDuplicate(&head);
	display(head);
    return 0;

}
//Delete All the duplicate Node from sorted Doubly Linked List
/*
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
	Node *prev;
};
void push(Node **head,int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=(*head);
	if((*head)!=NULL) {
		(*head)->prev=newNode;
	}
	(*head)=newNode;
}
void display(Node *head) {
	while(head!=NULL) {
		cout<<head->data<<" ";
		head=head->next;
	}
}
void deleteNode(Node **head,Node *del) {
	if((*head)==NULL || del==NULL) {
		return;
	}
	if((*head)==del) {
		(*head)=del->next;
	}
	if(del->next!=NULL) {
		del->next->prev=del->prev;
	}
	if(del->prev!=NULL) {
		del->prev->next=del->next;
	}
	delete(del);
	return;
}
void removeDuplicate(Node **head) {
	if((*head)==NULL) {
		return;
	}
	Node *cur=(*head);
	Node *next;
	while(cur->next!=NULL) {
		if(cur->data==cur->next->data) {
			deleteNode(head,cur->next);
		}
		else {
			cur=cur->next;
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *head=NULL;
	push(&head,10);
	push(&head,20);
	push(&head,30);
	push(&head,40);
	push(&head,40);
	push(&head,50);
	push(&head,60);
	push(&head,60);
	push(&head,70);
	removeDuplicate(&head);
	display(head);
    return 0;

}
*/