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
Node *newNode(int data) {
    Node *temp = new Node;
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}
void display(Node *p) {
    Node *first = p;
    if(p != NULL) {
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
    Node* head = newNode(1);
    head -> next = newNode(2);
    head -> next -> next = newNode(3);
    head -> next -> next -> next = newNode(4);
    head -> next -> next -> next -> next = head;
    display(head);
    return 0;
}