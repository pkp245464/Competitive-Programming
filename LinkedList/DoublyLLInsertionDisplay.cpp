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
    Node *next,*prev;
};
void push(Node** head, int data) {
    Node* first = new Node();
    first -> data = data;
    first -> next = (*head);
    first -> prev = NULL;
    if((*head) != NULL) {
        (*head) -> prev = first;
    }
    (*head) = first;
}
void insertAfter(Node* prev, int data) {
    if(prev == NULL) {
        return;
    }
    Node* first = new Node();
    first -> data = data;
    first -> next = prev->next;
    prev -> next = first;
    first -> prev = prev;
    if(first -> next != NULL) {
        first -> next -> prev = first;
    }
}
void append(Node** head, int data) {
    Node* first = new Node();
    Node *last = *head;
    first -> data = data;
    first -> next = NULL;
    if(*head == NULL) {
        first -> prev = NULL;
        *head = first;
        return;
    }
    while(last -> next != NULL) {
        last = last -> next;
    }
    last -> next = first;
    first -> prev = last;
    return;
}
void display(Node* p) {
    Node *last;
    cout << "Traversal in forward direction" << nl;
    while(p != NULL) {
        cout << p-> data << " ";
        last = p;
        p = p-> next;
    }
    cout << "Traversal in reverse direction" << nl;
    while(last != NULL) {
        cout << last -> data << " ";
        last = last -> prev;
    }
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Node* head = NULL;
    append(&head,6);
    push(&head,7);
    push(&head,1);
    append(&head,4);
    insertAfter(head -> next,8);
    display(head);
    return 0;
}