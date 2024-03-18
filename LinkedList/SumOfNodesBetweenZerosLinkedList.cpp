#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Node {
public:
	int data;
	Node *next;
};
Node *push(int val) {
	Node *temp = new Node();
	temp->data = val;
	temp->next = NULL;
	return temp;
}
void display(Node *head) {
	while(head->next) {
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"->"<<head->data;
}

void inPlaceStore(Node *head) {
	if(head->data == 0) {
		head = head->next;
	}
	Node *ans = head;
	Node *temp = head;
	int sum = 0;
	while(temp) {
		if(temp->data != 0) {
			sum += temp->data;
			temp = temp->next;
		}
		else {
			ans->data = sum;
			ans->next = temp->next;
			temp = temp->next;
			ans = temp;
			sum = 0;
		}
	}
	display(head);
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *head;
    head = push(3);
    head->next = push(2);
    head->next->next = push(0);
    head->next->next->next = push(4);
    head->next->next->next->next = push(5);
    head->next->next->next->next->next = push(0);
    head->next->next->next->next->next->next = push(6);
    head->next->next->next->next->next->next->next = push(7);
    inPlaceStore(head);
    return 0;
}
