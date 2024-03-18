#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class LRUCache {
	list<int>dq;
	unordered_map<int,list<int>::iterator>m;
	int capSize;
public:
	LRUCache(int);
	void refer(int);
	void display();
};
LRUCache::LRUCache(int n) {
	capSize=n;
}
void LRUCache::refer(int x) {
	if(m.find(x)==m.end()) {
		if(dq.size()==capSize) {
			int last=dq.back();
			dq.pop_back();
			m.erase(last);
		}
	}
	else {
		dq.erase(m[x]);
	}
	dq.push_front(x);
	m[x]=dq.begin();
}
void LRUCache::display() {
	for(auto it=dq.begin();it!=dq.end();it++) {
		cout<<*it<<" ";
	}
	cout<<nl;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	LRUCache *p=new LRUCache(4);
	p->refer(1);
	p->refer(2);
	p->refer(3);
	p->refer(4);
	p->refer(5);
	p->display();
    return 0;
}

