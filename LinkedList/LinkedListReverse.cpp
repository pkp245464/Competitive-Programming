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
static void reverse(Node** head) {
    Node *current = *head,*prev = NULL,*next = NULL;
    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void Push(Node** head, int data) {
    Node* first = new Node();
    first -> data = data;
    first -> next = (*head);
    (*head) = first;
}
void display(Node* p) {
    while(p != NULL){
        cout << p-> data << " ";
        p = p-> next;
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
    Push(&head,1);
    Push(&head,2);
    Push(&head,3);
    Push(&head,4);
    Push(&head,5);
    display(head);
    reverse(&head);
    display(head);
    return 0;
}