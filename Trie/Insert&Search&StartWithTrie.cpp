#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Node {
public:
	Node *links[26];
	bool flag = false;
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	void put(char ch,Node *root) {
		links[ch - 'a'] = root;
	}
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	void setEnd() {
		flag = true;
	}
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node *root;
public:
    Trie() {
    	root = new Node();
    }
    void insert(string word) {
    	Node *newNode = root;
    	for(int i = 0;i < word.size();i++) {
    		if(!newNode->containKey(word[i])) {
    			newNode->put(word[i],new Node());
    		}
    		newNode = newNode->get(word[i]);
    	}
    	newNode->setEnd();
    }
    bool search(string word) {
        Node *newNode = root;
        for(int i = 0;i < word.size();i++) {
        	if(!newNode->containKey(word[i])) {
        		return false;
        	}
        	newNode = newNode->get(word[i]);
        }
        return newNode->isEnd();
    }
    bool startsWith(string prefix) {
        Node *newNode = root;
        for(int i = 0;i<prefix.size();i++) {
        	if(!newNode->containKey(prefix[i])) {
        		return false;
        	}
        	newNode = newNode->get(prefix[i]);
        }
        return true;
    }
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	// 1-> Insert ||  2-> Search  || 3-> Start With 
	int n=5;
	vector<int>type = {1,1,2,3,2};
	vector<string>value = {"hello","help","help","hel","hel"};
	Trie t;
	for(int i = 0; i < n; i++) {
		if(type[i] == 1) {
			t.insert(value[i]);
		}
		else if(type[i] == 2) {
			if(t.search(value[i])) {
				cout<<"True"<<nl;
			}
			else {
				cout<<"False"<<nl;
			}
		}
		else {
			if(t.startsWith(value[i])) {
				cout<<"True"<<nl;
			}
			else {
				cout<<"False"<<nl;
			}
		}
	}
    return 0;
}
