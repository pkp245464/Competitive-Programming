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
int fun(Node *root,int &maxi) {
	if(root == NULL) {
		return 0;
	}
	int leftMaxPath = max(0,fun(root->left,maxi));
	int rightMaxPath = max(0,fun(root->right,maxi));

	int val = root->data;

	maxi = max(maxi,(leftMaxPath + rightMaxPath) + val);
	return max(leftMaxPath,rightMaxPath) + val;
}
int maxPathSum(Node* root) {
	int maxi = INT_MIN;
	fun(root,maxi);
	return maxi;    
}
int main() {
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root = createNode(-10);
	root->left = createNode(9);
	root->right = createNode(20);
	root->right->left = createNode(15);
	root->right->right = createNode(7);

	cout<<maxPathSum(root)<<nl;
    return 0;
}