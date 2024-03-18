#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};
void iterativeDisplay(Node* p){
    while (p!=0){
        cout<<p->data<<" ";
        p=p->next;
    }

}
void recursiveDisplay(Node *head) {
	if(head==NULL) return;
	cout<<head->data<<" ";
	recursiveDisplay(head->next);
}
int main(){
    Node* head=NULL;
    Node* second=NULL;
    Node* third=NULL;
	//we can create like "Node* head = new Node();"
    head=new Node();
    second=new Node();
    third=new Node();
    Node* pkp=NULL;
    pkp=new Node();

    pkp->data=81;
    pkp->next=head;
    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;
    iterativeDisplay(pkp);

    return 0;

}