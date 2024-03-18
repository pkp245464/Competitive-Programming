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
class Solution {
	Node *prev = NULL;
public:
	void flatten(Node *root) {
		if(root == NULL) {
			return;
		}
		flatten(root->right);
		flatten(root->left);

		root->right = prev;
		root->left = NULL;
		prev = root;
	}
};

int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *root = createNode(1);
	root->left = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(4);
	root->right = createNode(5);
	root->right->right = createNode(6);
	root->right->right->left = createNode(7);

	Solution obj;
	obj.flatten(root);

	while(root->right != NULL) {
		cout<<root->data<<"->";
		root = root->right;
	}
	cout<<root->data;
	
    return 0;
}
