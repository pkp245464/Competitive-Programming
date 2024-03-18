#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define phb push_back
#define phf push_front
#define ppf pop_front
#define ppb pop_back
#define in insert
#define as assign
#define nle "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
class Node {
public:
	int data;
	Node *left,*right;
};
Node *createNode(int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
bool isMirror(Node *a,Node *b) {
	if(a==NULL && b==NULL)
		return true;
	if(a==NULL || b==NULL)
		return false;
	return a->data == b->data && isMirror(a->left,b->right) && isMirror(a->right,b->left);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif				
	Node *a=createNode(1);
	a->left=createNode(3);
	a->right=createNode(2);
	a->right->left=createNode(5);
	a->right->right=createNode(4);
	
	Node *b=createNode(1);
	b->left=createNode(2);
	b->right=createNode(3);
	b->left->left=createNode(4);
	b->left->right=createNode(5);
	
	if(isMirror(a,b))
		cout<<"YES"<<nle;
	else
		cout<<"NO"<<nle;
    return 0;
}