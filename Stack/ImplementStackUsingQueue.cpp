#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class MyStack {
public:
    queue<int>q;
    void push(int x) {
        int s = q.size();
    	q.push(x);
    	for(int i = 0; i < s; i++) {
    		q.push(q.front());
    		q.pop();
    	}    
    }
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        if(q.empty() == false) return false;
        return true;
    }
    int size() {
    	return q.size();
    }
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	MyStack s;
	s.push(3);
	s.push(2);
	s.push(4);
	s.push(1);
	cout<<"Top: "<<s.top()<<nl;
    cout<<"Size: "<<s.size()<<nl;
    cout<<"Pop: "<<s.pop()<<nl;
    cout<<"Top: "<<s.top()<<nl;
    cout<<"Size: "<<s.size()<<nl;
    return 0;
}
