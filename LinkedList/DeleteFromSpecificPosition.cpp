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
void push(Node **head,int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->next=(*head);
	(*head)=newNode;
}
void deleteNode(Node **head,int pos) {
	if(*head==NULL) return;
	Node *temp=*head;
	if(pos==0) {
		*head=temp->next;
		delete(temp);
		return;
	}
	for(int i=0;temp!=NULL && i<pos-1;i++) {
		temp=temp->next;		
	}
	if(temp==NULL || temp->next==NULL) {
		return;
	}
	Node *store=temp->next->next;
	delete(temp->next);
	temp->next=store;
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
	push(&head,10);
	deleteNode(&head,3);
	display(head);
    return 0;
}

