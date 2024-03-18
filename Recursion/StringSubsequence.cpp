#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"  
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void fun(int ind,string &str,string &s) {
    if(ind == s.size()) {
        cout<<str<<nl;
        return;
    }
    fun(ind + 1,str,s);
    str = str + s[ind];
    fun(ind + 1,str,s);
    str.pop_back();
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "ABC";
    string str = "";
    fun(0,str,s);    
    return 0;
}