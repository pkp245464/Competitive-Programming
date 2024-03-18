// if Preorder & Inorder Given Then Find Postorder
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
Node *constructTree(int preStart,int preEnd,vector<int>&preorder,int inStart,int inEnd,vector<int>&inorder,map<int,int>&m) {
	if(preStart > preEnd || inStart > inEnd) {
		return NULL;
	}
	Node *root = createNode(preorder[preStart]);
	int elem = m[root->data];
	int nElem = elem - inStart;

	root->left = constructTree(preStart + 1,preStart + nElem,preorder,inStart,elem - 1,inorder,m);
	root->right = constructTree(preStart + nElem + 1,preEnd,preorder,elem + 1,inEnd,inorder,m);

	return root;
}
Node* buildTree(vector<int>& inorder,vector<int>& preorder) {
	int preStart = 0,preEnd = preorder.size() - 1;
	int inStart = 0, inEnd = inorder.size() - 1;
	map<int,int>m;
	for(int i = inStart; i <= inEnd; i++) {
		m[inorder[i]] = i;
	}
	return constructTree(preStart,preEnd,preorder,inStart,inEnd,inorder,m);
}
void postorder(Node *root) {
	if(root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>inorder = {40,20,50,10,60,30};
	vector<int>preorder = {10,20,40,50,30,60};
	Node *root = buildTree(inorder,preorder);
	postorder(root);
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// If Postorder	& Inorder Given Then Find Preorder

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
Node *constructTree(int inStart,int inEnd,vector<int>&inorder,int posStart,int posEnd,vector<int>&postorder,map<int,int>&m) {
	if(posStart > posEnd || inStart > inEnd) {
		return NULL;
	}
	Node *root = createNode(postorder[posEnd]);
	
	int inRoot = m[postorder[posEnd]];
	int numLeft = inRoot - inStart;

	root->left = constructTree(inStart,inRoot - 1,inorder,posStart,posStart + numLeft - 1,postorder,m);
	root->right = constructTree(inRoot + 1,inEnd,inorder,posStart + numLeft,posEnd - 1,postorder,m);
	return root;
}
Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if(inorder.size() != postorder.size()) {
		return NULL;
	}  
	map<int,int>m;
	for(int i = 0; i < inorder.size(); i++) {
		m[inorder[i]] = i;
	}
	int inStart = 0, inEnd = inorder.size() - 1;
	int posStart = 0,posEnd = inorder.size() - 1;
	return constructTree(inStart,inEnd,inorder,posStart,posEnd,postorder,m);
}
void preorder(Node *root) {
	if(root == NULL) {
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>inorder = {9,3,15,20,7};
	vector<int>postorder = {9,15,7,20,3};
	Node *root = buildTree(inorder,postorder);
	preorder(root);
    return 0;
}
*/