// Policy based data structures C++ STL
// order_of_key(k): number of elements less than k
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// Time complexity: O(logn) for both

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//with template
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>;

//without template
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_multiset;

int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin >> n >> k;
    // ordered_set ot; // int type // if you want to define "pair<int,int>" then at above part define in the place of "int" to "pair<int,int>"
    
    ordered_set<int>ot;
    // ordered_set<pair<int,int>>ot;

    ot.insert(10);
    ot.insert(10);
    ot.insert(20);
    ot.insert(30);
    ot.insert(40);
    ot.insert(50);
    ot.insert(60);
    cout << ot.size() << nl;
    cout << *ot.find_by_order(5) << nl;
    cout << ot.order_of_key(60) << nl;
    return 0;
}
//Practice 
//https://cses.fi/problemset/task/1144/
//https://cses.fi/problemset/task/2163/
//https://codeforces.com/contest/1042/problem/D
//https://codeforces.com/contest/1915/problem/F