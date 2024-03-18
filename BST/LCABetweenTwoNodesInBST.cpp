#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define phb push_back
#define phf push_front
#define ppf pop_front
#define ppb pop_back
#define in insert
#define as assign   
#define nle "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
class Node {
public:
	int data;
	Node *left,*right;
	Node(int data) {
		this->data=data;
		this->left=this->right=NULL;
	}
};
Node *lca(Node *root,int n1,int n2) {
	if(root==NULL) return NULL;
	if(root->data>n1 && root->data>n2)
		return lca(root->left,n1,n2);
	if(root->data<n1 && root->data<n2)
		return lca(root->right,n1,n2);
	return root;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif			
	Node *root=new Node(20);
	root->left=new Node(8);
	root->right=new Node(22);
	root->left->left=new Node(4);
	root->left->right=new Node(12);
	root->left->right->left=new Node(10);
	root->left->right->right=new Node(14);
	int n1=4,n2=22;
	Node *t=lca(root,n1,n2);
	cout<<t->data<<nle;
    return 0;
}