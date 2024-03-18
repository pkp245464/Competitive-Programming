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
void minMaxValueInBST(Node *root) {
	Node *curr1 = root;
	Node *curr2 = root;
	
	while(curr1->left != NULL) {
		curr1=curr1->left;
	}
	cout<<"Minimum: "<<curr1->val<<nl;

	while(curr2->right != NULL) {
		curr2=curr2->right;
	}
	cout<<"Maximum: "<<curr2->val;
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
	minMaxValueInBST(root);
    return 0;
}