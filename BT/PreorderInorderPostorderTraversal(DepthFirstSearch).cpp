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
	Node (int val) {
		data=val;
		left=right=NULL;
	}
};
void preorder(Node *temp) {
	if(temp==NULL) return;
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
}
void inorder(Node *temp) {
	if(temp==NULL) return;
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}
void postorder(Node *temp) {
	if(temp==NULL) return;
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" ";
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif    
	Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<"Preorder traversals: \n";
    preorder(root);
    cout<<"\nInorder traversals: \n";
    inorder(root);
    cout<<"\nPostorder traversals: \n";
    postorder(root);
    return 0;
}
