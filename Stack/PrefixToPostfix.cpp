#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
    switch(c) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;  
}
string prefixToPostfix(string exp) {
    stack<string>s;
    int len=exp.size();

    for(int i=len-1;i>=0;i--) {
        if(isOperator(exp[i])) {
            string op1=s.top(); s.pop();
            string op2=s.top(); s.pop();
            string temp=op1+op2+exp[i];
            s.push(temp);
        }
        else {
            s.push(string(1,exp[i]));
        }
    }
    return s.top();
}

int main(){

    string exp="*-A/BC-/AKL";
    cout<<prefixToPostfix(exp);
    return 0;
}
