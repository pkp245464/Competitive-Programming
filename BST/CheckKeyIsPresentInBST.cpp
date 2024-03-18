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
Node *insert(Node *root,int key) {
	if(root == NULL) return createNode(key);
	if(key < root->val) {
		root->left = insert(root->left,key);
	}
	else {
		root->right = insert(root->right,key);
	}
	return root;
}
void search(Node *root,int key) {
	while(root != NULL && root->val != key) {
		root = root->val > key ? root->left : root->right;
	}
	if( root != NULL && root->val == key) {
		cout<<"Key Is Present"<<nl;
	}
	else {
		cout<<"Key Is Not Present"<<nl;
	}
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	Node *root = NULL;
	root = insert(root,50); 
	root = insert(root,30); 
	root = insert(root,20); 
	root = insert(root,40); 
	root = insert(root,70); 
	root = insert(root,60); 
	root = insert(root,80); 
	search(root,50);
	return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Second Method

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
Node *insert(Node *root,int key) {
	if(root == NULL) return createNode(key);
	if(key < root->val) {
		root->left = insert(root->left,key);
	}
	else {
		root->right = insert(root->right,key);
	}
	return root;
}
Node *searchInBST(Node *root,int key) {
	if(root == NULL) {
		return NULL;
	}
	if(root->val == key) {
		return root;
	}
	if(root->val > key) {
		return searchInBST(root->left,key);
	}
	return searchInBST(root->right,key);
} 
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	Node *root = NULL;
	root = insert(root,50); 
	root = insert(root,30); 
	root = insert(root,20); 
	root = insert(root,40); 
	root = insert(root,70); 
	root = insert(root,60); 
	root = insert(root,80); 
	
	if(searchInBST(root,51) == NULL) {
		cout<<"Key Is Not Present"<<nl;			
	}
	else {
		cout<<"Key Is Present"<<nl;
	}
	return 0;
}
*/


/*
        50
      /    \
    30      70 
   /  \    /  \
  20  40  60  80
 
*/