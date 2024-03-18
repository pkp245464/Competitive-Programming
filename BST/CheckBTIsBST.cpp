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
	Node(int data) {
		this->data=data;
		this->left=this->right=NULL;
	}
};
bool isBST(Node *root,Node *l=NULL,Node *r=NULL) {
	if(root==NULL) 
		return true;
	if(l!=NULL && root->data<=l->data) 
		return false;
	if(r!=NULL && root->data>=r->data)
		return false;
	return isBST(root->left,l,root) && 
		   isBST(root->right,r,root);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif			
	Node *root=new Node(3);
	root->left=new Node(2);
	root->right=new Node(5);
	root->left->left=new Node(1);
	root->left->right=new Node(4);
	if(isBST(root,NULL,NULL))
		cout<<"Is BST"<<nle;
	else
		cout<<"Not a BST"<<nle; 
    return 0;
}