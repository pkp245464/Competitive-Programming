#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
class Node {
public:
	int data;
	Node *left,*right;
};
Node *createNode(int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
void fun(Node *root) {
	if(root == NULL) {
		return;
	}
	int child = 0;
	if(root->left) {
		child += root->left->data; 
	}
	if(root->right) {
		child += root->right->data;
	}
	if(child < root->data) {
		if(root->left) {
			root->left->data = root->data;
		}
		else if(root->right) {
			root->right->data = root->data;
		}
	}
	fun(root->left);
	fun(root->right);

	int total = 0;
	if(root->left) {
		total += root->left->data;
	}
	if(root->right) {
		total += root->right->data;
	}
	if(root->left || root->right) {
		root->data = total;
	} 
}
void childrenSumProperty(Node *root) {
	fun(root);
}
void levelOrder(Node *root) {
	if(root==NULL) return;
	queue<Node*>q;
	q.push(root);
	while(q.empty() == false) {  
		Node *temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left != NULL)  
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *root = createNode(2);
	root->left = createNode(35);
	root->left->left = createNode(2);
	root->left->right = createNode(3);
	root->right = createNode(10);
	root->right->left = createNode(5);
	root->right->right = createNode(2);
	childrenSumProperty(root);
	levelOrder(root);
    return 0;
}

/*
// old Binary Tree
          2
       /    \
	 35	     10
	/  \    /  \
   2    3  5    2
*/
/*
// New Binary Tree
         50
       /    \
	 38	     12
	/  \    /  \
   35   3  10   2
*/

