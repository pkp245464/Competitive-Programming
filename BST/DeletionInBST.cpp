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
	int val;
	Node *left,*right;
};
Node *createNode(int data) {  
	Node *temp = new Node();
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}
Node *insert(Node *root,int key) {
	if(root == NULL) {
		return createNode(key);
	}
	Node *cur = root;
	while(true) {
		if(cur->val <= key) {
			if(cur->right != NULL) {
				cur = cur->right;
			}
			else {
				cur->right = createNode(key);
				break;
			}
		}
		else {
			if(cur->left != NULL) {
				cur = cur->left;
			}
			else {
				cur->left = createNode(key);
				break;
			}
		}
	}
	return root;
}
Node *inorderSuccsessor(Node *root) {
	Node *cur = root;
	while(cur != NULL && cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}
Node *deleteInBST(Node *root,int key) {
	if(root == NULL) {
    	return root;
    }
	if(root->val > key) {
		root->left = deleteInBST(root->left,key);
	}
	else if(root->val < key) {
		root->right = deleteInBST(root->right,key);
	}
	else {
		if(root->left == NULL) {
			Node *temp = root->right;
			delete(root);
			return temp;
		}
		else if(root->right == NULL) {
			Node *temp = root->left;
			delete(root);
			return temp;
		}
		Node *temp = inorderSuccsessor(root->right);
		root->val = temp->val;
		root->right = deleteInBST(root->right,temp->val);
	}
	return root;
}
void inorder(Node *root) {
	if(root == NULL) {
		return;
	}
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root=NULL;
	root = insert(root,50); 
	root = insert(root,30); 
	root = insert(root,20); 
	root = insert(root,40); 
	root = insert(root,70); 
	root = insert(root,60); 
	root = insert(root,10); 
	root=deleteInBST(root,20);
	root=deleteInBST(root,30);
	root=deleteInBST(root,50);
	inorder(root);
    return 0;
}