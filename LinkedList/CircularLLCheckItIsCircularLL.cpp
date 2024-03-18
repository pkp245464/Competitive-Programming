#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Node{
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
    (*head) = first;
}
bool isCircular(Node *head){
    if(head == NULL) {
        return true;
    }
    Node *first = head -> next;
    while(first != NULL && first != head) {
        first = first -> next;
    }
    return first == head;
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
    cout << (isCircular(head) ? "Yes" : "No") << nl;
    return 0;
}