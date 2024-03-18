#include<bits/stdc++.h>
using namespace std;

bool BracketBalanced(string exp) {  
	stack<char>s;
	char c;
	for(int i=0;i<exp.length();i++) {
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') {
			s.push(exp[i]);
			continue;
		}
		if(s.empty())
			return false;
		switch(exp[i]) {
			case ')': 
				c=s.top();
				s.pop();
				if(c=='{' || c=='[')
					return false;
				break;
			case '}': 
				c=s.top();
				s.pop();
				if(c=='(' || c=='[')
					return false;
				break;
			case ']': 
				c=s.top();
				s.pop();
				if(c=='(' || c=='{')
					return false;
				break;
		}
	}
	return (s.empty());
}

int main(){
 #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string exp;
	cin>>exp;
	if(BracketBalanced(exp))
		cout<<"Balanced"<<"\n";
	else
		cout<<"Not Balanced"<<"\n";
       
    return 0;
}
