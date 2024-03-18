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
bool isPresent(Node *head,int data) {
	Node *check=head;
	while(check!=NULL) {
		if(check->data==data) {
			return true;
		}
		check=check->next;
	}
	return false;
}
void display(Node *head) {
	if(head==NULL) return;
	cout<<head->data<<" ";
	display(head->next);
}
Node *getUnion(Node *head1,Node *head2) {
	Node *res=NULL;
	Node *t1=head1,*t2=head2;
	while(t1!=NULL) {
		push(&res,t1->data);
		t1=t1->next;
	}
	while(t2!=NULL) {
		if(!isPresent(res,t2->data)) {
			push(&res,t2->data);
		}
		t2=t2->next;
	}
	return res;
}
Node *getIntersection(Node *head1,Node *head2) {
	Node *res=NULL;
	Node *t=head1;
	while(t!=NULL) {
		if(isPresent(head2,t->data)) {
			push(&res,t->data);
		}
		t=t->next;
	}
	return res;
}	
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *head1=NULL;
	push(&head1,50);
	push(&head1,40);
	push(&head1,30);
	push(&head1,20);
	push(&head1,10);
	cout<<"First List: ";
	display(head1);
	cout<<nl;

	Node *head2=NULL;
	push(&head2,90);
	push(&head2,30);
	push(&head2,40);
	push(&head2,70);
	push(&head2,10);
	cout<<"Second List: ";
	display(head2);
	cout<<nl;
	
	Node *Intersection=NULL;
	Intersection=getIntersection(head1,head2);
	cout<<"Intersection: ";
	display(Intersection);
	cout<<nl;
	
	Node *Union=NULL;
	Union=getUnion(head1,head2);
	cout<<"Union: ";
	display(Union);
    cout<<nl;

    return 0;
}

