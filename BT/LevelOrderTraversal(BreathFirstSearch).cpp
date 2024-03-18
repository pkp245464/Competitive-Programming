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
	Node *left,*right;
};
Node *createNode(int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;    
}
void levelOrder(Node *root) {
	if(root==NULL) return;
	queue<Node*>q;
	q.push(root);
	while(q.empty()==false) {   //Or while(!q.empty())
		Node *temp=q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left!=NULL)  //)Or if(temp->left)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	levelOrder(root);
    return 0;
}

// Second Method

/*
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
	Node *left,*right;
};
Node *createNode(int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;    
}
vector<vector<int>> levelOrder(Node *root) {
	vector<vector<int>>ans;
	if(root == NULL) return ans;
	queue<Node*>q;
	q.push(root);
	while(q.empty() == false) {
		int n = q.size();
		vector<int>row;
		for(int i = 0; i < n; i++) {
			Node *temp = q.front();
			q.pop();
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
			row.push_back(temp->data);
		}
		ans.push_back(row);
	}
	return ans;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root=createNode(3);
	root->left=createNode(9);
	root->right=createNode(20);
	root->right->left=createNode(15);
	root->right->right=createNode(7);
	vector<vector<int>>ans =  levelOrder(root);
    for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<nl;
	}
    return 0;
}
*/