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
class Queue {
public:
	stack<int>s1,s2;
	void enQueue(int x) {
		while(!s1.empty()) {
			s2.push(s1.top()),s1.pop();
		}
		s1.push(x);
		while(!s2.empty()) {
			s1.push(s2.top()),s2.pop();
		}
	}
	int deQueue() {
		if(s1.empty()) {
			cout<<"Q is Empty";
			exit(0);
		}
		int x=s1.top();
		s1.pop();
		return x;
	}
};

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Queue q;
	q.enQueue(10);
	q.enQueue(20);	
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	cout<<q.deQueue()<<"\n";
	cout<<q.deQueue()<<"\n";
	cout<<q.deQueue()<<"\n";
    return 0;
}