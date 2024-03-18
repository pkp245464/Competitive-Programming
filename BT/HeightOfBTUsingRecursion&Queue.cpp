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
	int data;
	Node *left,*right;
};
Node *createNode(int data) {
	Node *newNode=new Node();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
//Finding Height using recursion
int heightOfBT(Node *temp) {
	if(temp==NULL) return 0;
	int ldepth=heightOfBT(temp->left);
	int rdepth=heightOfBT(temp->right);
	return max(ldepth,rdepth)+1;

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
	cout<<heightOfBT(root);
    return 0;
}
// Or
/*
//Finding Height using queue
void heightOfBT(Node *root) {
	int depth=0;
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		Node *temp=q.front();
		q.pop();
		if(temp==NULL) {   
			depth++;
		}
		if(temp!=NULL) {
			if(temp->left) {
				q.push(temp->left);
			}
			if(temp->right) {
				q.push(temp->right);
			}
		}
		else if(!q.empty()) {
			q.push(NULL);
		}
	}
	cout<<depth<<nle;
}
*/