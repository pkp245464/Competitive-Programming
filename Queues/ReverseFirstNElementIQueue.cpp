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
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
void reverseQFNElement(int k,queue<int>& q) {
	if(q.empty()==true || k>q.size())
		return;
	if(k<=0)
		return;
	stack<int>s;
	for(int i=0;i<k;i++) {
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	} 
	for(int i=0;i<q.size()-k;i++) {
		q.push(q.front());
		q.pop();
	}
}
void Display(queue<int>& q) {
	while(!q.empty()) {
		cout<<q.front()<<" ";

		q.pop();
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	queue<int>q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);
	q.push(80);
	q.push(90);
	q.push(100);
	int k=5;
	reverseQFNElement(k,q);
	Display(q);
    return 0;
}