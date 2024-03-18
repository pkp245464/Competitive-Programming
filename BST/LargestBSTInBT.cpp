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
	int val;
	Node *left,*right;
};
Node *createNode(int data) {  
	Node *temp = new Node();
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}
class NodeValue {
public:
	int minNode,maxNode,maxSize;
	NodeValue(int minNode,int maxNode,int maxSize) {
		this->maxNode = maxNode;
		this->minNode = minNode;
		this->maxSize = maxSize;
	}
};
class Solution {
private:
	NodeValue largestBSTSubTreeHelper(Node *root) {
		if(root == NULL) {
			return NodeValue(INT_MAX,INT_MIN,0);
		}
		auto left = largestBSTSubTreeHelper(root->left);
		auto right = largestBSTSubTreeHelper(root->right);

		if(left.maxNode < root->val && root->val < right.minNode) {
			return NodeValue(min(root->val,left.minNode),max(root->val, right.maxNode),left.maxSize + right.maxSize + 1);
		}
		return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
	}
public:
	int largestBSTSubtree(Node* root) {
        return largestBSTSubTreeHelper(root).maxSize;
    }
};
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	Solution *p = new Solution();
	Node *root = createNode(50);
	root->left = createNode(30);
	root->right = createNode(60);
	root->left->left = createNode(5);
	root->left->right = createNode(20);
	root->right->left = createNode(45);
	root->right->right = createNode(70);
	root->right->right->left = createNode(65);
	root->right->right->right = createNode(80);
	
	cout<<p->largestBSTSubtree(root)<<nl;
	return 0;
}
