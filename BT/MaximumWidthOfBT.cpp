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
int maxWidth(Node *root) {
	if(root == NULL) return 0;
	
	int ans = 0;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	
	while(!q.empty()) {
		int n = q.size();
		int curMin = q.front().second;
		int leftMost,rightMost;

		for(int i = 0; i < n;i++) {
			int curId = q.front().second - curMin;
			Node *temp = q.front().first;
			q.pop();
			
			if(i == 0) {
				leftMost = curId;
			}
			if(i == n - 1) {
				rightMost = curId;
			}
			if(temp->left) {
				q.push({temp->left,curId*2LL+1});
			}
			if(temp->right) {
				q.push({temp->right,curId*2LL+2});
			}
		}
		ans = max(ans,rightMost - leftMost + 1);
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
	root->right->right = createNode(5);

	root->left->left->left = createNode(6);
	root->right->right->right = createNode(7);
	
	cout<<maxWidth(root)<<nl;
    return 0;
}
