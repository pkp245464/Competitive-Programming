#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------///
bool isPalindrome(string s,int l,int r) {
    if(l == r) {
        return true;
    }  
    if(l > r) {
        return true;
    } 
    if(s[l] != s[r]) {
        return false;
    }
    return isPalindrome(s,l + 1,r - 1);
}
int main(){
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    string s = "aabaa";
    int n = s.size();
    if(isPalindrome(s,0,n - 1)) {
        cout << "Palindrome" << nl;
    }
    else {
        cout << "Not a Palindrome" <<  nl;
    }
    return 0;
}