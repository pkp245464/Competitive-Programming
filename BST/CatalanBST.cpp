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
void preorder(Node *root) {
	if(root == NULL) {
		return;
	}
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}
vector<Node*> constructBST(int start,int end) {
	vector<Node*>tree;
	if(start > end) {
		tree.push_back(NULL);
		return tree;
	}
	for(int i = start; i <= end; i++) {
		vector<Node*>leftSubTree = constructBST(start,i - 1);
		vector<Node*>rightSubTree = constructBST(i + 1,end);
		for(int j = 0; j < leftSubTree.size(); j++) {
			Node *left = leftSubTree[j];
			for(int k = 0; k < rightSubTree.size(); k++) {
				Node *right = rightSubTree[k];
				Node *temp = createNode(i);
				temp->left = left;
				temp->right = right;
				tree.push_back(temp);
			}	
		}
	}
	return tree;	
}
vector<Node*> generateTrees(int n) {
	vector<Node*>ans = constructBST(1,n);
	return ans;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	vector<Node*>ans = generateTrees(3);
	for(int i = 0; i < ans.size(); i++) {
		preorder(ans[i]);
		cout<<nl;
	}
	return 0;
}
