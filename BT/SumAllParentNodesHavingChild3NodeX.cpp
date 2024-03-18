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
void sumOfNode(Node *root,int &sum,int x) {
	if(root == NULL) {
		return;
	}
	if((root->left && root->left->data == x) ||(root->right && root->right->data == x)) {
		sum += root->data;
	}
	sumOfNode(root->left,sum,x);
	sumOfNode(root->right,sum,x);
}
int sumOfParent(Node *root,int x) {
	int sum=0;
	sumOfNode(root,sum,x);
	return sum;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *root = createNode(4);
	root->left = createNode(2);
	root->right = createNode(5);
	root->left->left = createNode(7);
	root->left->right = createNode(2);
	root->right->left = createNode(2);
	root->right->right = createNode(3);
	int x = 2;
	cout<<sumOfParent(root,x)<<nl;
    return 0;
}
/*

	4        
   / \       
  2   5      
 / \ / \     
7  2 2  3    

*/

