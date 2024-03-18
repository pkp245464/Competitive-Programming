#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------///
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
	if(root == NULL) {
		return createNode(key);
	}
	Node *cur = root;
	while(true) {
		if(cur->val <= key) {
			if(cur->right != NULL) {
				cur = cur->right;
			}
			else {
				cur->right = createNode(key);
				break;
			}
		}
		else {
			if(cur->left != NULL) {
				cur = cur->left;
			}
			else {
				cur->left = createNode(key);
				break;
			}
		}
	}
	return root;
}
Node *inorderSuccsessor(Node *root) {
	Node *cur = root;
	while(cur != NULL && cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}
void inorder(Node *root,vector<int>&nums) {
	if(root == NULL) {
		return;
	}
	inorder(root->left,nums);
	nums.push_back(root->val);
	inorder(root->right,nums);
}
int kthSmallest(Node* root, int k) {
	vector<int>arr;	        
	inorder(root,arr);
	return arr[k - 1];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root=NULL;
	root = insert(root,50); 
	root = insert(root,30); 
	root = insert(root,20); 
	root = insert(root,40); 
	root = insert(root,70); 
	root = insert(root,60); 
	int k = 1;
	cout<<kthSmallest(root,k)<<nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------///
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
	if(root == NULL) {
		return createNode(key);
	}
	Node *cur = root;
	while(true) {
		if(cur->val <= key) {
			if(cur->right != NULL) {
				cur = cur->right;
			}
			else {
				cur->right = createNode(key);
				break;
			}
		}
		else {
			if(cur->left != NULL) {
				cur = cur->left;
			}
			else {
				cur->left = createNode(key);
				break;
			}
		}
	}
	return root;
}
Node *inorderSuccsessor(Node *root) {
	Node *cur = root;
	while(cur != NULL && cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}
int kthSmallest(Node* root, int k) {
	stack<Node*>s;
	Node *temp = root;
	int cnt = 0;
	while(true) {
		if(temp != NULL) {
			s.push(temp);
			temp = temp->left;
		}
		else {
			if(s.empty() == true) {
				break;
			}
			temp = s.top();
			s.pop();
			cnt++;
			if(cnt == k) {
				return temp->val;
			}
			temp = temp->right;
		}
	}
	return -1;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root=NULL;
	root = insert(root,50); 
	root = insert(root,30); 
	root = insert(root,20); 
	root = insert(root,40); 
	root = insert(root,70); 
	root = insert(root,60); 
	int k = 1;
	cout<<kthSmallest(root,k)<<nl;
    return 0;
}
*/