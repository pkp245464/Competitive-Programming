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
void reverseQueue(queue<int>& q) {
	stack<int>s;
	while(!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}
void Display(queue<int>& q) {
	while(!q.empty()) {
		cout<<q.front()<<"\n";
		q.pop();
	}
}
int main() {
    fastinput;
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

	reverseQueue(q);
	Display(q);
    return 0;
}
