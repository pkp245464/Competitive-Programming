//TC: O(n)
//SC: O(n)

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int N = 32;
struct TrieNode {
    int val; 
    TrieNode *a[2];
};
TrieNode *newNode() {
    TrieNode *tmp = new TrieNode;
    tmp->val = 0;
    tmp->a[0] = tmp->a[1] = 0;
    return tmp;
}
void insert(TrieNode *root,int pre_xor) {
    TrieNode *tmp = root;
    for(int i = N - 1; i >= 0; i--)   {
        bool val = pre_xor & (1 << i);
        if(tmp->a[val] == 0) {
            tmp->a[val] = newNode(); 
        }
        tmp = tmp->a[val];
    } 
    tmp->val = pre_xor;
}
int query(TrieNode *root,int pre_xor) {
    TrieNode *tmp = root;
    for(int i = N - 1; i >= 0; i--) {
        bool val = pre_xor & (1 << i);
        if(tmp->a[1 - val] != 0) {
            tmp = tmp->a[1-val];
        }
        else if (tmp->a[val] != 0) {
            tmp = tmp->a[val];
        }
    }
    return pre_xor ^ (tmp->val);
}
int maxSubarrayXOR(vector<int>&a) {
    int n = (int)a.size();
    TrieNode *root = newNode();
    insert(root,0);
    int ans = INT_MIN,pre_xor =0;
    for(int i = 0; i < n; i++) {
        pre_xor = pre_xor ^ a[i];
        insert(root,pre_xor);
        ans = max(ans,query(root,pre_xor));
    }
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << maxSubarrayXOR(a) << nl;
    }
    return 0;
}