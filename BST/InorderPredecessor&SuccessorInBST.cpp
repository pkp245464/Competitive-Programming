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
	int key;
	Node *left,*right;
};
Node *createNode(int data) {
	Node *temp=new Node();
	temp->key=data;
	temp->left=temp->right=NULL;
	return temp;
}
Node *insert(Node *root,int key) {
	if(root==NULL) return createNode(key);
	if(key<root->key)
		root->left=insert(root->left,key);
	else
		root->right=insert(root->right,key);
	return root;
}
void presuc(Node *root,Node *&pre,Node *&suc,int key) {
	if(root==NULL) return;
	if(root->key==key) {
		if(root->left!=NULL) {
			Node *temp=root->left;
			while(temp->right) {
				temp=temp->right;
			}
			pre=temp;
		}
		if(root->right!=NULL) {
			Node *temp=root->right;
			while(temp->left) {
				temp=temp->left;
			}
			suc=temp;
		}
		return;
	}
	if(root->key>key) {
		suc=root;
		presuc(root->left,pre,suc,key);
	}
	else {
		pre=root;
		presuc(root->right,pre,suc,key);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root=NULL;
	root=insert(root,50); 
	insert(root,30); 
	insert(root,20); 
	insert(root,40); 
	insert(root,70); 
	insert(root,60); 
	insert(root,80); 
	int key=65;
	Node *pre=NULL,*suc=NULL;
	presuc(root,pre,suc,key);
	if(pre!=NULL)
		cout<<"Predecessor is: "<<pre->key<<nle;
	else
		cout<<"No Predecessor"<<nle;
	if(suc!=NULL)
		cout<<"Successor is: "<<suc->key;
	else
		cout<<"No Successor"<<nle;
    return 0;
}