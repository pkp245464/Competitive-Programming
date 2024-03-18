//Brute force Approach

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
bool getPath(Node *root,vector<Node*>&ans,Node *x) {
	if(root == NULL) return false;
	ans.push_back(root);
	if(root == x) {
		return true;
	}
	if(getPath(root->left,ans,x) || getPath(root->right,ans,x)) {
		return true;
	}
	ans.pop_back();
	return false;
}
Node* lowestCommonAncestor(Node *root,Node *p,Node *q) {
	vector<Node*>arr1,arr2;
	if(getPath(root,arr1,p) == false || getPath(root,arr2,q) == false) {
		return 0;
	}
	int i = 0;
	for(i = 0; i < min(arr1.size(),arr2.size()); i++) {
		if(arr1[i] != arr2[i]) {
			break;
		}
	}
	return arr1[i - 1];
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
	Node *p = root->left->right;
	Node *q = root->right->right;  
	
	cout<<lowestCommonAncestor(root,p,q)->data;
    
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*
//Optimize Method

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
Node *lowestCommonAncestor(Node *root,Node *p,Node *q) {
	if(root == NULL || root == p|| root == q) {
		return root;
	}
	Node *left = lowestCommonAncestor(root->left,p,q);
	Node *right = lowestCommonAncestor(root->right,p,q);

	if(left == NULL) {
		return right;
	}
	else if(right == NULL) {
		return left;
	}
	else {
		return root;
	}
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
	
	Node *p = root->left->right;  //contain - 5
	Node *q = root->right->right;  //contain - 7
	
	cout<<lowestCommonAncestor(root,p,q)->data;
    
    return 0;
}
*/

/*
// Main Function 
//Node *p = createNode(5);  we separtely created node
//Node *q = createNode(7);

//Lowest Common Ancestor function
//Wrong
if(root == NULL || root == p|| root == q) {  // here we compare two diferent address that why we got wrong answer
		return root;
}

//Right
if(root == NULL || root->data == p->data || root->data == q->data) {
		return root;
}

*/

