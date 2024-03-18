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
bool getPath(Node *root,vector<int>&ans,int x) {
	if(root == NULL) return false;
	ans.push_back(root->data);
	if(root->data == x) {
		return true;
	}
	if(getPath(root->left,ans,x) || getPath(root->right,ans,x)) {
		return true;
	}
	ans.pop_back();
	return false;
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
	
	int x = 7;
	vector<int>ans;
	if(!getPath(root,ans,x)) {
		cout<<"Path Not Exist"<<nl;
	}
	for(int i = 0 ; i < ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
    return 0;
}
