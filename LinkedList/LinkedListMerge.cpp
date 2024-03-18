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
void moveNode(Node** destRef,Node** sourceRef);
Node* sortedMerge(Node* a,Node* b) {
    Node temp;
    Node* tail =& temp;
    temp.next = NULL;
    while(true) {
        if(a == NULL) {
            tail -> next = b;
            break;
        }
        else if(b == NULL) {
            tail -> next = a;
            break;
        }
        if(a -> data <= b -> data) {
            moveNode(&(tail -> next),&a);
        }
        else {
            moveNode(&(tail -> next),&b);
        }
        tail = tail -> next;
    }
    return(temp.next);
}
void moveNode(Node** destRef,Node** sourceRef) {
    Node* first = *sourceRef;
    assert(first != NULL);
    *sourceRef = first -> next;
    first -> next = *destRef;
    *destRef = first;
}
void push(Node** head, int data) {
    Node* first = new Node();
    first -> data = data;
    first -> next = (*head);
    (*head) = first;
}
void display(Node *p) {
    while(p != NULL){
        cout << p-> data << " ";
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
    Node *ans = NULL,*a = NULL,*b = NULL;
    push(&a,15);
    push(&a,10);
    push(&a,5);

    push(&b,20);
    push(&b,3);
    push(&b,2);

    ans = sortedMerge(a,b);
    display(ans);
    return 0;
}