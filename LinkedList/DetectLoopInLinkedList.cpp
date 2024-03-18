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
bool detectLoop(Node *head) {
	unordered_set<Node*>st;
	while(head!=NULL) {
		if(st.find(head)!=st.end()) {
			return true;
		}
		st.insert(head);
		head=head->next;
	}
	return false;
}
//or Using Two Pointer Approach
bool detectLoop1(Node *head) {
	if(head==NULL || head->next==NULL) return false;
	Node *fast=head;
	Node *slow=head;
	while(fast->next!=NULL and fast->next->next!=NULL) {
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow) return true;
	}
	return false;
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
	head->next->next->next->next->next=head;
	if(detectLoop(head))
		cout<<"Loop Found !!!"<<nl;
	else cout<<"No Loop"<<nl;
    return 0;
}
// Floyd’s Cycle-Finding Algorithm 
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
};
void push(Node **head,int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->next=(*head);
	(*head)=newNode;
}
bool detectLoop(Node *head) {
	Node *slow=head,*fast=head;
	while(slow && fast && fast->next) {
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast) return true;
	}
	return false;	
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
	head->next->next->next->next->next=head;
	if(detectLoop(head))
		cout<<"Loop Found !!!"<<nl;
	else cout<<"No Loop"<<nl;
    return 0;
}
*/
