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
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int alphbetSize=26;
struct TrieNode {
	struct TrieNode *child[alphbetSize];
	bool isEnd;
};
struct TrieNode *getNode(void) {
	struct TrieNode *pNode=new TrieNode();
	pNode->isEnd=false;
	for(int i=0;i<alphbetSize;i++) {
		pNode->child[i]=NULL;
	}
	return pNode;
}
void insertNode(struct TrieNode *root,string key) {
	struct TrieNode *pCrawl=root;
	for(int i=0;i<key.size();i++) {
		int index=key[i]-'a';
		if(pCrawl->child[index]==NULL)
			pCrawl->child[index]=getNode();
		pCrawl=pCrawl->child[index];
	}
	pCrawl->isEnd=true;
}
bool search(struct TrieNode *root,string key) {
	struct TrieNode *pCrawl=root;
	for(int i=0;i<key.size();i++) {
		int index=key[i]-'a';
		if(pCrawl->child[index]==NULL) {
			return false;
		}
		pCrawl=pCrawl->child[index];
	}
	return pCrawl->isEnd;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string keys[]={"the","a","there","answer",
					"any","was","bye","their"};
	int n=sizeof(keys)/sizeof(keys[0]);
	struct TrieNode *root=getNode();
	for(int i=0;i<n;i++) {
		insertNode(root,keys[i]);
	}
	//cout<<(search(root,"the")?"Yes":"No")<<nl;
	cout<<(search(root,"these")?"Yes":"No")<<nl;
	return 0;
}

