#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") {
        return "0";
    }
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    int n = num1.size() + num2.size();
    string ans(n,'0');
    for(int i = 0; i < num2.size(); i++) {
        int a = num2[i] - '0';
        for(int j = 0; j < num1.size(); j++) {
            int b = num1[j] - '0';
            int numZeros = i + j;

            int carry = ans[numZeros] - '0';
            int multi = a * b + carry;
            ans[numZeros] = (multi % 10) + '0';
            ans[numZeros + 1] += (multi / 10);
        }
    }
    if(ans.back() == '0') {
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string num1 = "498828660196840477629533";
    string num2 = "840477629533498828660196";
    cout << multiply(num1,num2) << nl;
    return 0;
}