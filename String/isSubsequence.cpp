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
    bool fun(int m,int n,string s,string t) {
        if(m == 0) return true;
        if(n == 0) return false;
        if(s[m - 1] == t[n - 1]) {
            return fun(m-1,n-1,s,t);
        }
        return fun(m,n-1,s,t);
    }
    bool isSubsequence(string s, string t) {
        return fun(s.size(),t.size(),s,t,);
    }
};
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    string s = "abc", t = "ahbgdc";
    cout<<p->isSubsequence(s,t);
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Using Two Pointer Approach

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0,j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        if(i == m) return true;
        else return false;
    }
};
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    string s = "abc", t = "ahbgdc";
    cout<<p->isSubsequence(s,t);
    return 0;
}
*/

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
    bool fun(int m,int n,string s,string t) {
        if(m == 0) return true;
        if(n == 0) return false;
        if(s[m - 1] == t[n - 1]) {
            return fun(m-1,n-1,s,t);
        }
        return fun(m,n-1,s,t);
    }
    bool isSubsequence(string s, string t) {
        return fun(s.size(),t.size(),s,t,);
    }
};
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    string s = "abc", t = "ahbgdc";
    cout<<p->isSubsequence(s,t);
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Using Two Pointer Approach

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0,j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        if(i == m) return true;
        else return false;
    }
};
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p = new Solution();
    string s = "abc", t = "ahbgdc";
    cout<<p->isSubsequence(s,t);
    return 0;
}
*/

