#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void computeLPSArray(vector<int>& pattern, vector<int>& lps) {
    int i = 1,len = 0,patternLen = pattern.size();
    lps[0] = 0;
    while(i < patternLen) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int KMPSearch(vector<int>&text,vector<int>&pattern) {
    int textLen = text.size();
    int patternLen = pattern.size();
    vector<int> lps(patternLen, 0);
    computeLPSArray(pattern, lps);
    int i = 0,j = 0,cnt = 0;
    while(i < textLen) {
        if(pattern[j] == text[i]) {
            i++;
            j++;
        }
        if(j == patternLen) {
            cnt++;
            j = lps[j - 1];
        }
        else if(i < textLen && pattern[j] != text[i]) {
            if(j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return cnt;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>text = {1,2,1,2,1,2,1};
    vector<int>pattern = {1,2,1};
    cout << KMPSearch(text,pattern) << nl; // 3
    return 0;
}