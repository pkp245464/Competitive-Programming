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
public  
	int data;
	Node *left;
	Node *right;
};
Node *createNode(int data) {
	Node *newNode=new Node();
	if(!newNode) {
		cout<<"Memory error\n";
		return NULL;  
	}
	newNode->data=data;  //OR:- newNode->left=NULL; newNode->right=NULL;
	newNode->left=newNode->right=NULL;
	return newNode;
}
Node *insertNode(Node *root,int data) {
	if(root==NULL) {
		root=createNode(data);
		return root;
	}
	queue<Node*>q;
	q.push(root);
	while(!q.empty()) {
		Node *temp=q.front();
		q.pop();
		if(temp->left!=NULL) q.push(temp->left);
		else {
			temp->left=createNode(data);
			break;
		}
		if(temp->right!=NULL) q.push(temp->right);
		else {
			temp->right=createNode(data);
			break;
		}
	}
	return root;
}
void inorder(Node *temp) {
	if(temp==NULL) return;
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
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
	root->right=createNode(9);
	root->right->left=createNode(15);
	root->right->right=createNode(8);
	cout<<"Inordered traversal before insertion:\n";
	inorder(root);
	cout<<nle;
	int key=27;
	root=insertNode(root,key);
	cout<<"Inordered traversal after insertion:\n";
	inorder(root);
	cout<<nle;
    return 0;
}

