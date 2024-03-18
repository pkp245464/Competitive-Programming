#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
class Node {
public:
	int data;
	Node *left;
	Node *right;
};
Node *createNode(int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
bool fun(Node *root1,Node *root2) {
	if(root1 == NULL || root2 == NULL) {
		return root1 == root2;
	}
	return (root1->data == root2->data) && fun(root1->left,root2->right) && fun(root1->right,root2->left);
}
bool isSymmetric(Node* root) {
	if(root == NULL) {
		return true;
	}
	return fun(root->left,root->right);        
}
int main() {
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(4);
	root->right->left = createNode(4);
	root->right->right = createNode(3);

	if(isSymmetric(root)) {
		cout<<" BT is Symmetric"<<nl;
	}
	else {
		cout<<" BT is not Symmetric"<<nl;	
	}
    return 0;
}