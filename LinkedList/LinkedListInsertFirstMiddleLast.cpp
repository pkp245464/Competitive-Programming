#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Node {
public:
    int data;
    Node* next;
};
//Insert the node at first postions means on head
void insertFirst(Node** head,int data) {
    Node* first = new Node();
    first -> data = data;
    first -> next = (*head);
    (*head) = first;
}
//insert the node in the middle
void insertMiddle(Node* prev,int data) {
    if(prev == NULL) {
        return;
    }
    Node* first = new Node();
    first -> data = data;
    first -> next = prev -> next;
    prev -> next = first;
}
//insert the node at the last
void insertLast(Node** lst,int data) {
    Node* first = new Node();
    Node* last = new Node();
    first -> data = data;
    first -> next = NULL;
    if(*lst == NULL){
        *lst = first;
        return;
    }
    while(last -> next != NULL) {
        last = last -> next;
    }
    last -> next = first;
    return;
}
void display(Node *p) {
    while(p != NULL) {
        cout << p -> data << " ";
        p = p -> next;
    }
	cout << nl;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Node* head = NULL;
    insertLast(&head,6); //node:6 
    insertFirst(&head,7); //node:7 6
    insertFirst(&head,1); //node:1,7,6
    insertLast(&head,4);  //node:1,7,6,4
    insertMiddle(head -> next,8);  //node:1,7,8,6,4
    display(head);
    return 0;
}