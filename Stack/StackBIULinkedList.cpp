#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int data;
    Stack *next;
};
Stack *NewNode(int data) {
    Stack *first=new Stack();
    first->data=data;
    first->next=NULL;
    return first;
}
int isEmpty(Stack *head) {
    return !head;
}
void push(Stack **head,int data) {
    Stack *first= NewNode(data);
    first->next=(*head);
    (*head)=first;
    cout<<data<<" Pushed to stack"<<"\n";
}
int pop(Stack **head) {
    if(isEmpty(*head))
        return INT_MIN;
    Stack *temp=(*head);
    (*head)=(*head)->next;
    int popped=temp->data;
    free(temp);
    return popped;
}
int peek(Stack *head) {
    if(isEmpty(head))
        return INT_MIN;
    return head->data;
}
int main() {
    Stack *head=NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    pop(&head);
    while(!isEmpty(head)) {
        cout<<peek(head)<<" ";
        pop(&head);
    }
    return 0;
}

