//Inorder Traversal
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
	int data;   
	Node *left;
	Node *right;
};
Node *newNode(int data) {
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
vector<int> morrisInorderTraversal(Node *root) {
	vector<int>ans;
	Node *cur = root;
	while(cur != NULL) {
		if(cur->left == NULL) {
			ans.push_back(cur->data);
			cur = cur->right;
		}
		else {
			Node *prev = cur->left;
			while(prev->right != NULL && prev->right != cur) {
				prev = prev->right;
			}
			if(prev->right == NULL) {
				prev->right = cur;
				cur = cur->left;
			}
			else {
				prev->right = NULL;
				ans.push_back(cur->data);
				cur = cur->right;
			}
		}
	}
	return ans;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node * root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> left -> right -> right = newNode(6);
	vector<int>ans = morrisInorderTraversal(root);
    for(int i = 0; i < ans.size(); i++) {
    	cout<<ans[i]<<" ";
    }
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Preorder Traversal

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
	int data;
	Node *left;
	Node *right;
};
Node *newNode(int data) {
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
vector<int> morrisPreorderTraversal(Node *root) {
	vector<int>ans;
	Node *cur = root;
	while(cur != NULL) {
		if(cur->left == NULL) {
			ans.push_back(cur->data);
			cur = cur->right;
		}
		else {
			Node *prev = cur->left;
			while(prev->right != NULL && prev->right != cur) {
				prev = prev->right;
			}
			if(prev->right == NULL) {
				prev->right = cur;
				ans.push_back(cur->data);
				cur = cur->left;
			}
			else {
				prev->right = NULL;
				cur = cur->right;
			}
		}
	}
	return ans;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node * root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> left -> right -> right = newNode(6);
	vector<int>ans = morrisPreorderTraversal(root);
    for(int i = 0; i < ans.size(); i++) {
    	cout<<ans[i]<<" ";
    }
    return 0;
}
*/