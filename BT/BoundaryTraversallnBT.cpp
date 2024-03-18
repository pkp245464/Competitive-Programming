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
bool isLeaf(Node *root) {
	return !root->left && !root->right;
}
void addLeftBoundary(Node *root,vector<int>&ans) {
	Node *cur = root->left;
	while(cur) {
		if(!isLeaf(cur)) {
			ans.push_back(cur->data);
		}
		if(cur->left) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}
}
void addRightBoundary(Node *root,vector<int>&ans) {
	Node *cur = root->right;
	vector<int>tmp;
	while(cur) {
		if(!isLeaf(cur)) {
			tmp.push_back(cur->data);
		}
		if(cur->right) {
				cur = cur->right;
		}
		else {
			cur = cur->left;
		}
	}
	for(int i = tmp.size() - 1; i >= 0; i--) {
		ans.push_back(tmp[i]);
	}
}
void addLeaves(Node *root,vector<int>&ans) {
	if(isLeaf(root)) {
		ans.push_back(root->data);
		return;
	}
	if(root->left) {
		addLeaves(root->left,ans);
	}
	if(root->right) {
		addLeaves(root->right,ans);
	}
}
vector<int> display(Node *root) {
	vector<int>ans;
	if(!root) return ans;
	if(!isLeaf(root)) {
		ans.push_back(root->data);
	}
	addLeftBoundary(root,ans);
	addLeaves(root,ans);
	addRightBoundary(root,ans);
	return ans;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node * root = createNode(1);
    root -> left = createNode(2);
    root -> left -> left = createNode(3);
    root -> left -> left -> right = createNode(4);
    root -> left -> left -> right -> left = createNode(5);
    root -> left -> left -> right -> right = createNode(6);
    root -> right = createNode(7);
    root -> right -> right = createNode(8);
    root -> right -> right -> left = createNode(9);
    root -> right -> right -> left -> left = createNode(10);
    root -> right -> right -> left -> right = createNode(11);
    
    vector<int>ans = display(root);
    for(int i = 0; i < ans.size(); i++) {
    	cout<<ans[i]<<" ";
    }
    return 0;
}
