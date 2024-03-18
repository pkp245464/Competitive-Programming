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
void insertSorted(Node** head, Node* first) {
    Node *current = *head;
    if(current == NULL) {
        first -> next = first;
        *head = first;
    }
    else if(current -> data >= first -> data) {
        while(current -> next != *head) {
            current = current -> next;
        }
        current -> next = first;
        first -> next = *head;
        *head = first;
    }
    else {
        while(current -> next != *head && current -> next -> data < first -> data) {
            current = current -> next;
        }
        first -> next = current -> next;
        current -> next = first;
    }
}
void display(Node *p){
    Node *first;
    if(p != NULL) {
        first = p;
        do {
            cout << first -> data << " ";
            first = first -> next;
        } while(first != p);
    }
    cout << nl;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>arr = {12, 56, 2, 11, 1, 90};
    Node *first,*head = NULL;
    for(auto it : arr) {
        first = new Node();
        first -> data = it;
        insertSorted(&head,first);
    }
    display(head);
    return 0;
}