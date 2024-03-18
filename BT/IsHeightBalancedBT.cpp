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
int dfsHeight(Node *root) {
	if(root == NULL) return 0;
	
	int leftHeight = dfsHeight(root->left);
	if(leftHeight == -1) return -1;
	
	int rightHeight = dfsHeight(root->right);
	if(rightHeight == -1) return -1;

	if(abs(leftHeight - rightHeight) > 1) return -1;

	return max(leftHeight,rightHeight) + 1;
}
bool isBalancedBT(Node *root) {
	return dfsHeight(root) != -1;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	
	cout<<isBalancedBT(root);
    return 0;
}
