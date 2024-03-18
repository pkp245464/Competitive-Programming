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
void deleteNode(Node **head,int key) {
	Node *temp=*head;
	Node *prev=NULL;
	if(temp!=NULL && temp->data==key) {
		*head=temp->next;
		delete temp;
		return;
	}
	else {
		while(temp!=NULL && temp->data!=key) {
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL) return;
		prev->next=temp->next;
		delete temp;
	}
}
void display(Node *head) {
	while(head!=NULL) {
		cout<<head->data<<" ";
		head=head->next;
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
	push(&head,50);
	deleteNode(&head,50);
	deleteNode(&head,40);
	display(head);
    return 0;
}

