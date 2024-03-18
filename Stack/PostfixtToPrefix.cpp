#include<bits/stdc++.h>
using namespace std;

bool isOperator(char x) {
    switch (x) {
        case '+':  
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}
string postfixToPrefix(string exp) {
    stack<string>s;
    int len=exp.size();

    for(int i=0;i<len;i++) {
        if(isOperator(exp[i])) {
            string op1=s.top(); s.pop();
            string op2=s.top(); s.pop();

            string temp=exp[i]+op2+op1;
            s.push(temp);
        }
        else {
            s.push(string(1,exp[i]));
        }
    }
    string ans="";
    while(!s.empty()) {
        ans+=s.top();
        s.pop();
    }
    return ans;
}
int main() {
    string exp="ABC/-AK/L-*";
    cout<<postfixToPrefix(exp);
    return 0;
}