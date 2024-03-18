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
void markParents(Node *root,unordered_map<Node*,Node*>&parent_track,Node *target) {
	queue<Node*>q;
	q.push(root);
	while(!q.empty()) {
		Node *cur = q.front();
		q.pop();
		if(cur->left) {
			parent_track[cur->left] = cur;
			q.push(cur->left);
		}
		if(cur->right) {
			parent_track[cur->right] = cur;
			q.push(cur->right);
		}
	}
}
vector<int> distanceK(Node* root,Node* target, int k) {
	unordered_map<Node*,Node*>parent_track;
	markParents(root,parent_track,target);

	unordered_map<Node*,bool>visited;
	queue<Node*>q;
	q.push(target);
	visited[target] = true;
	int cur_level = 0;
	while(!q.empty()) {
		int n = q.size();
		if(cur_level++ == k) {
			break;
		}
		for(int i = 0; i < n; i++) {
			Node *cur = q.front();
			q.pop();

			if(cur->left && !visited[cur->left]) {
				q.push(cur->left);
				visited[cur->left] = true;
			}
			if(cur->right && !visited[cur->right]) {
				q.push(cur->right);
				visited[cur->right] = true;
			}
			if(parent_track[cur] && !visited[parent_track[cur]]) {
				q.push(parent_track[cur]);
				visited[parent_track[cur]] = true;
			}
		}
	}
	vector<int>ans;
	while(!q.empty()) {
		Node *cur = q.front();
		q.pop();
		ans.push_back(cur->data);
	}
	return ans;
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *root = createNode(3);
	root->left = createNode(5);
	root->left->left = createNode(6);
	root->left->right = createNode(2);
	root->left->right->left = createNode(7);
	root->left->right->right = createNode(4);
	root->right = createNode(1);
	root->right->left = createNode(0);
	root->right->right = createNode(8);
	int k = 2;
	Node *target = root->left;
	vector<int>ans = distanceK(root,target,k);
	for(int i = 0; i < ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
    return 0;
}
