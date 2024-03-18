#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
// iterative method
bool isPalindrome(string &s) {
    int n = (int)s.size();
    for(int i = 0; i < n / 2; i++) { 
        if(s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}
// using prebuilt function
bool isPalindrome(string &s) {
    string t = s; 
    reverse(t.begin(),t.end());
    return s == t;
}
// recursive method
bool isPalindrome(int ind, string&s) {
    if(ind >= s.size() / 2) {
        return true;    
    }
    if(s[ind] != s[s.size() - ind - 1]) {
        return false;    
    }
    return isPalindrome(ind + 1,s);
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "ABBCBA";
    cout << isPalindrome(0,s) << nl;
    return 0;
}