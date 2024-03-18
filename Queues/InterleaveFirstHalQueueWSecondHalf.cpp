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
void InterleaveQueue(queue<int>&q) {
	if(q.size()%2!=0)
		cout<<"NO"<<"\n";
	
	int half=q.size()/2;
	stack<int>s;
	for(int i=0;i<half;i++) {
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}
	for(int i=0;i<half;i++) {
		q.push(q.front());
		q.pop();
	}
	for(int i=0;i<half;i++) {
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
	//cout<<q.size()<<" "<<s.size()<<"\n";
}
int main() {
    fastinput;
 #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	queue<int>q;
	q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
	InterleaveQueue(q);
	int len=q.size();
	for(int i=0;i<len;i++) {
		cout<<q.front()<<" ";
		q.pop();
	}
    return 0;
}
