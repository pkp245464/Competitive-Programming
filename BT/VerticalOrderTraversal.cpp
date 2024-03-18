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
vector<vector<int>> verticalTraversal(Node *root) {
	map<int,map<int,multiset<int>>>m;
	queue<pair<Node*,pair<int,int>>>q;
	q.push({root,{0,0}});
	while(!q.empty()) {
		auto p = q.front();
		q.pop();
		Node *temp = p.first;
		
		int x = p.second.first;
		int y = p.second.second;
		m[x][y].insert(temp->data);
		
		if(temp->left) {
			q.push({temp->left,{x - 1,y + 1}});
		}
		if(temp->right) {
			q.push({temp->right,{x + 1,y + 1}});
		}
	}
	vector<vector<int>>ans;
	for(auto it : m) {
		vector<int>col;
		for(auto q : it.second) {
			col.insert(col.end(),q.second.begin(),q.second.end());
		}
		ans.push_back(col);
	}
	return ans;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node * root = createNode(1);
    root -> left = createNode(2);
    root -> left -> left = createNode(4);
    root -> left -> right = createNode(10);
    root -> left -> left -> right = createNode(5);
    root -> left -> left -> right -> right = createNode(6);
    root -> right = createNode(3);
    root -> right -> left = createNode(9);
    root -> right -> right = createNode(10);
      
    vector<vector<int>>ans = verticalTraversal(root);
    for(int i = 0; i < ans.size(); i++) {
    	for(int j = 0; j < ans[i].size(); j++) {
    		cout<<ans[i][j]<<" ";
    	}
    	cout<<nl;
    }
    return 0;
}
