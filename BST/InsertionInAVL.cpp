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
	int key;
	Node *left,*right;
	int height;
};
int max(int a,int b);
int height(Node *root) {
	if(root==NULL)
		return 0;
	return root->height;
}
int max(int a,int b) {
	return (a>b)?a:b;
}
Node *createNode(int data) {
	Node *newNode=new Node();
	newNode->key=data;
	newNode->left=newNode->right=NULL;
	newNode->height=1;
	return newNode;
}
Node *rightRotate(Node *y) {
	Node *x=y->left;
	Node *T2=x->right;
	x->right=y;
	y->left=T2;

	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return x;
}
Node *leftRotate(Node *x) {
	Node *y=x->right;
	Node *T2=y->left;
	y->left=x;
	x->right=T2;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}
int getBalance(Node *root) {
	if(root==NULL)
		return 0;
	return height(root->left)-height(root->right);
}
Node* insert(Node* root, int data){
	if(root==NULL)
		return createNode(data);

	if (data< root->key)
		root->left = insert(root->left,data);
	else if (data>root->key)
		root->right = insert(root->right,data);
	else
		return root;
	
	root->height=1+max(height(root->left),height(root->right));
	int balance=getBalance(root);

	if(balance>1 && data<root->left->key)
		return rightRotate(root);
	if(balance<-1 && data>root->right->key)
		return leftRotate(root);
	if(balance>1 && data>root->left->key) {
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance<-1 && data<root->right->key) {
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void preorder(Node *temp) {
	if(temp!=NULL) {
		cout<<temp->key<<" ";
		preorder(temp->left);
		preorder(temp->right);
	}
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);
	root=insert(root,25);
	preorder(root);
	return 0;
}

