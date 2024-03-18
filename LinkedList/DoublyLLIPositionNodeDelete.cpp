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
void Push(Node **head,int data) {
    Node *first = new Node();
    first -> data = data;
    first -> prev = NULL;
    first -> next = (*head);
    if((*head) != NULL) {
        (*head) -> prev = first;
    }
    (*head) = first;
}
void DeleteNode(Node **head,Node *del) {
    if(*head == NULL|| del == NULL) {
        return;
    }
    if(*head == del) {
        *head = del -> next;
    }
    if(del -> next != NULL) {
        del -> next -> prev = del -> prev;
    }
    if(del -> prev != NULL) {
        del -> prev -> next = del -> next;
    }
    free(del);
}
void Position(Node **head,int n) {
    if(*head == NULL || n <= 0) {
        return;
    }
    Node *current = *head;
    for(int i = 1; current != NULL && i < n; i++) {
        current = current -> next;
    }
    if(current == NULL) {
        return;
    }
    DeleteNode(head,current);
}
void display(Node *p) {
    while(p != NULL){
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
    Node *head = NULL;
    Push(&head,1);
    Push(&head,2);
    Push(&head,3);
    Push(&head,4);
    Push(&head,5);
    Position(&head,5);
    display(head);
    return 0;
}   