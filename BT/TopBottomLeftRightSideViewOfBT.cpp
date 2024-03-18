// Top View Of Binary Tree

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
vector<int> topView(Node *root) {
	vector<int>ans;
	if(root == NULL) return ans;
	map<int,int>m;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	while(!q.empty()) {
		auto it = q.front();
		q.pop();
		Node *temp = it.first;
		int line  = it.second;
		if(m.find(line) == m.end()) { 
			m[line] = temp->data;
		}
		if(temp->left != NULL) {
			q.push({temp->left,line - 1});
		}
		if(temp->right != NULL) {
			q.push({temp->right,line + 1});
		}
	}
	for(auto it = m.begin(); it != m.end(); it++) {
		ans.push_back(it->second);
	}
	return ans;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node *root = createNode(10);
	root->left = createNode(20);
	root->right = createNode(30);
	root->left->left = createNode(40);
	root->left->right = createNode(60);
	root->right->left = createNode(90);
	root->right->right = createNode(100);
	
	vector<int>ans = topView(root);
	for(int i = 0; i < ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Bottom View Of Binary Tree

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
vector<int> bottomView(Node *root) {
	vector<int>ans;
	if(root == NULL) return ans;
	map<int,int>m;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	while(!q.empty()) {
		auto it = q.front();
		q.pop();
		Node *temp = it.first;
		int line = it.second;
		m[line] = temp->data;
		if(temp->left != NULL) {
			q.push({temp->left,line - 1});
		}
		if(temp->right != NULL) {
			q.push({temp->right,line + 1});
		}
	}
	for(auto it = m.begin(); it != m.end(); it++) {
		ans.push_back(it->second);
	}
	return ans;
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
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	root->left->right->left = createNode(8);
	root->left->right->right = createNode(9);
	
	vector<int>ans = bottomView(root);
	for(int i = 0; i < ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Right Side View Of Binary Tree

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
void traversal(Node *root,int level,vector<int>&ans) {
	if(root == NULL) return;
	if(ans.size() == level) {
		ans.push_back(root->data);
	}
	traversal(root->right,level + 1,ans);
	traversal(root->left,level + 1,ans);
}
vector<int> rightSideView(Node *root) {
	vector<int>ans;
	traversal(root,0,ans);
	return ans;
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
	root->right->right = createNode(7);
	root->left->right->left = createNode(6);

	vector<int>ans = rightSideView(root);
	for(int i = 0; i < ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
// Left Side View Of Binary Tree

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n "
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
void traversal(Node *root,int level,vector<int>&ans) {
	if(root == NULL) return;
	if(ans.size() == level) {
		ans.push_back(root->data);
	}
	traversal(root->left,level + 1,ans);
	traversal(root->right,level + 1,ans);
}
vector<int> leftSideView(Node *root) {
	vector<int>ans;
	traversal(root,0,ans);
	return ans;
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
	root->right->right = createNode(7);
	root->left->right->left = createNode(6);

	vector<int>ans = leftSideView(root);
	for(int i = 0; i < ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
    return 0;
}
*/