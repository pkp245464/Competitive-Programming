#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------///
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
bool isValidBST(Node *root,Node *min=NULL,Node *max=NULL) {
	if(root == NULL) {
		return true;
	}
	if(min != NULL && root->val <= min->val) {
		return false;
	}
	if(max != NULL && root->val >= max->val) {
		return false;
	}
	bool leftValid = isValidBST(root->left,min,root);
	bool rightValid = isValidBST(root->right,root,max);
	return leftValid && rightValid;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root = NULL;
	root = insert(root,50); 
	root = insert(root,30); 
	root = insert(root,20); 
	root = insert(root,40); 
	root = insert(root,70); 
	root = insert(root,60); 
	
	if(isValidBST(root,NULL,NULL)) {
		cout<<"BST Is Valid"<<nl;
	}
	else {
		cout<<"BST Is Not Valid"<<nl;	
	}
    return 0;
}