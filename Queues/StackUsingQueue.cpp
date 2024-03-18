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
class Stack {
	queue<int>q1,q2;
	int curr_size;
public:
	Stack() {
		curr_size=0;
	}
	void push(int x) {
		curr_size++;
		q2.push(x);
		while(!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}
		queue<int>q=q1;
		q1=q2;
		q2=q;
	}
	void pop() {
		if(q1.empty())
			return;
		q1.pop();
		curr_size--;
	}
	int top() {
		if(q1.empty())
			return -1;
		return q1.front();
	}
	int size() {
		return curr_size;
	}
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<s.size()<<"\n";
	cout<<s.top()<<"\n"; s.pop();
    cout<<s.top()<<"\n"; s.pop();
    cout<<s.top()<<"\n"; s.pop();
    cout<<s.size()<<"\n";
    return 0;
}