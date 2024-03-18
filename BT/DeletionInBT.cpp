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
	Node *left;  
	Node *right;
};
Node *createNode(int data) {
	Node *temp=new Node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(Node *temp) {

	if(!temp) return;
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}
void deletDeepest(Node *root,Node *dnode) {
	queue<Node*>q;
	q.push(root);
	Node *temp;
	while(!q.empty()) {
		temp=q.front();
		q.pop();
		if(temp==dnode) {
			temp=NULL;
			delete dnode;
			return;
		}
		if(temp->right) {
			if(temp->right==dnode) {
				temp->right=NULL;
				delete dnode;
				return;
			}
			else q.push(temp->right);
		}
		if(temp->left) {
			if(temp->left==dnode) {
				temp->left=NULL;
				delete dnode;
				return;
			}
			else q.push(temp->left);
		}
	}
}  
Node *deletion(Node *root, int data) {
	if(root==NULL) return NULL;
	if(root->left==NULL && root->right==NULL) {
		if(root->data==data)
			return NULL;
		else root;
	}
	queue<Node*>q;
	q.push(root);
	Node *temp;
	Node *dataNode=NULL;
	while(!q.empty()) {
		temp=q.front();
		q.pop();
		if(temp->data==data) dataNode=temp;
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
	if(dataNode!=NULL) {
		int x=temp->data;
		deletDeepest(root,temp);
		dataNode->data=x;
	}
	return root;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *root=createNode(10);
	root->left=createNode(11);
	root->left->left=createNode(7);
	root->left->right=createNode(12);
	root->right=createNode(9);
	root->right->left=createNode(15);
	root->right->right=createNode(8);
	inorder(root);
	int key=11;
	root=deletion(root,key);
	cout<<nle;
	inorder(root);
    return 0;
}

