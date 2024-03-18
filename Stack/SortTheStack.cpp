#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------/// 
class Solution {
public:
    void insert(stack<int>&s,int temp) {
        if(s.size() == 0 || s.top() <= temp) {
            s.push(temp);
            return;
        }
        int val = s.top();
        s.pop();
        insert(s,temp);
        s.push(val);
    }
    void sortStack(stack<int>&s) {
        if(s.size() == 1) return;
        int temp = s.top();
        s.pop();
        sortStack(s);
        insert(s,temp); 
    }
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    //5
    //4 2 1 3 0
    int n;
    cin>>n;
    stack<int>s;
    while(n--) {
        int val;
        cin>>val;
        s.push(val);
    }
    p->sortStack(s);
    vector<int>ans;
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    //Ans: 4 3 2 1 0
    return 0;

}
