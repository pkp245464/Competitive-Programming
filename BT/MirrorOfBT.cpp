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
	Node *left,*right;
};
Node *createNode(int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right=NULL;
	return newNode;
}
// void mirrorOfBT(Node *root) {
// 	if(root == NULL) return;
// 	queue<Node*>q;
// 	q.push(root);
// 	while(!q.empty()) {
// 		Node *curr = q.front();
// 		q.pop();
// 		swap(curr->left,curr->right);
// 		if(curr->left) {
// 			q.push(curr->left);
// 		} 
// 		if(curr->right) {
// 			q.push(curr->right);
// 		} 
// 	}
// }

//Recursive of Mirror of BT
void mirrorOfBT(Node *root) {
	if(root == NULL) return;
	else {
		Node *temp;
		mirrorOfBT(root->left);
		mirrorOfBT(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}
void inorder(Node *temp) {
	if(temp == NULL) return;
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
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	inorder(root);
	mirrorOfBT(root);
	cout<<nl;
	inorder(root);
    return 0;
}
