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
class QUTS {
	stack<int>s1;
	stack<int>s2;
public:
	void push(int x) {
		s1.push(x);
	}
	int pop() {
		if(s1.empty() && s2.empty()) {
			cout<<"Queue is empty\n";
			return -1;
		}
		if(s2.empty()) {
			while(!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		int topval=s2.top();
		s2.pop();
		return topval;
	}
	bool empty() {
		if(s1.empty() && s2.empty())
			return true;
		return false;
	}
};
int main() {
    fastinput;
 #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	QUTS q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout<<q.pop()<<"\n";
	q.push(7);
	cout<<q.pop()<<"\n";
	cout<<q.pop()<<"\n";
	cout<<q.pop()<<"\n";
	cout<<q.pop()<<"\n";
	cout<<q.pop()<<"\n";
    return 0;
}

