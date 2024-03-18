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
int heightOfBT(Node *root,int &diameter) {
	if(root == NULL) return 0;
	int l = heightOfBT(root->left,diameter);
	int r = heightOfBT(root->right,diameter);
	diameter = max(diameter,l+r);
	return max(l,r)+1;
}
int diameterOfBT(Node *root) {
	int diameter = 0;
	heightOfBT(root,diameter);
	return diameter;
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
	cout<<diameterOfBT(root)<<nl;
    return 0;
}
