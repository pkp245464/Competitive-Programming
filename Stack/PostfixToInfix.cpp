#include<bits/stdc++.h>
using namespace std;
  
bool isOperator(char x) {
    return (x>='a' && x<='z') || (x>='A' && x<='Z');
}
string postfixToInfix(string exp) {
    stack<string>s;
    for(int i=0;exp[i]!='\0';i++) {
        if(isOperator(exp[i])) {
            string op(1,exp[i]);
            s.push(op);
        }
        else {
            string op1=s.top(); s.pop();
            string op2=s.top(); s.pop();
            s.push("(" + op2 + exp[i] + op1 + ")" );
        }
    }
    return s.top();
}
int main() {
    string exp="ab*c+";
    cout<<postfixToInfix(exp);
    return 0;
}
