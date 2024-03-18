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
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right=NULL;
	return newNode;
}
vector<vector<int>> zigzagLevelOrder(Node* root) {
	vector<vector<int>>ans;
	if(root == NULL) return ans;
	queue<Node*>q;
	q.push(root);
	bool leftToRight = true;
	while(q.empty() == false) {
		int n = q.size();
		vector<int>row(n);
		for(int i = 0; i < n; i++) {
			Node *temp = q.front();
			q.pop();
			
			int ind = (leftToRight) ? i : (n - 1 - i);
			row[ind]  = temp->data;
			
			if(temp->left) {
				q.push(temp->left);
			}
			if(temp->right) {
				q.push(temp->right);
			}
		}
		leftToRight =! leftToRight;
		ans.push_back(row);
	}
	return ans;	        
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(7);
	root->left->right = createNode(6);
	root->right->left = createNode(5);
	root->right->right = createNode(4);
	
	vector<vector<int>>ans = zigzagLevelOrder(root);
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<nl;
	}
    return 0;
}

