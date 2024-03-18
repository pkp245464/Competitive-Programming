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
class Node{
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
Node *insert(Node *root,int key) {
	if(root==NULL) return createNode(key);
	if(root->data>key)
		root->left=insert(root->left,key);
	else if(root->data<key)
		root->right=insert(root->right,key);
	return root;
}
Node *leafDelete(Node *root) {
	if(root==NULL) return NULL;
	if(root->left==NULL && root->right==NULL) {
		free(root);
		return NULL;
	}
	root->left=leafDelete(root->left);
	root->right=leafDelete(root->right);
	return root;
}
void inorder(Node *root) {
	if(root!=NULL) {
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif			
	Node *root=NULL;
	root=insert(root,20);
	insert(root,10);
	insert(root,5);
	insert(root,15);
	insert(root,30);
	insert(root,25);
	insert(root,35);
	inorder(root);
	leafDelete(root);
	cout<<nle;
	inorder(root);
    return 0;
}