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
    Node *next;
};
void Push(Node **head,int data) {
    Node *first = new Node();
    Node *temp = *head;
    first -> data = data;
    first -> next = *head;
    if(*head != NULL) {
        while(temp -> next != *head) {
            temp = temp -> next;
        }
        temp -> next = first;
    }
    else {
        first -> next = first;
    }
    *head = first;
}
void deleteNode(Node **head, int key) {
    if(*head == NULL) {
        return;
    }
    if((*head) -> data == key && (*head) -> next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *last = *head,*d;
    if((*head) -> data == key) {
        while(last -> next != *head) {
            last = last -> next;
        }
        last -> next = (*head) -> next;
        free(*head);
        *head = last -> next;
    }
    while(last -> next != *head && last -> next -> data != key) {
        last = last -> next;
    }
    if(last -> next -> data == key) {
        d = last -> next;
        last -> next = d -> next;
        free(d);
    }
    else {
        cout << "No such key found!!!" << nl;
    }
}
void display(Node *p) {
    Node *first = p;
    if(p != NULL) {
        do {
            cout << first -> data << " ";
            first = first -> next;
        } while(first != p);
    }
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Node* head = NULL;
    Push(&head,2);
    Push(&head,5);
    Push(&head,7);
    Push(&head,8);
    Push(&head,10);
    deleteNode(&head,7);
    deleteNode(&head,5);
    deleteNode(&head,8);
    deleteNode(&head,3);
    display(head);
    return 0;
}