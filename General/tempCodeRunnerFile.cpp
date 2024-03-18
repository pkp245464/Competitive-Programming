#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
using namespace std;
//-----------------------------------------------------------: Define :----------------------------------------------------------------///
using ll = long long;
using llu = unsigned long long;
using ld = long double;
#define nl "\n"
#define PI 3.1415926535897932384626433832795
#define testCases int tt; cin >> tt; while(tt--)
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//---------------------------------------------------------------: PBDS :--------------------------------------------------------------///
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; // *find_by_order,order_of_key
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>;
//-----------------------------------------------------------: Debugging :-------------------------------------------------------------///
#ifndef ONLINE_JUDGE
#define db(x) cerr << #x << " "; _print(x); cerr << nl;
#else
#define db(x)
#endif
void _print(int x) {cerr << x;}
void _print(ll x) {cerr << x;}
void _print(llu x) {cerr << x;}
void _print(char x) {cerr << x;}
void _print(string x) {cerr << x;}
void _print(float x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(ld x) {cerr << x;}
void _print(bool x) {cerr << x;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//------------------------------------------------------: Modular Arithmetic :---------------------------------------------------------///
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
ll modular(ll x) { 
    return ((x % MOD + MOD) % MOD);
}
ll add(ll a,ll b) { 
    return modular(modular(a) + modular(b));
}
ll mul(ll a,ll b) { 
    return modular(modular(a) * modular(b));
}
//----------------------------------------------------------: Run & RNG :-------------------------------------------------------------///
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (llu)rng() % B;
}
//-----------------------------------------------------------: pkp245464 :------------------------------------------------------------///              
int main() {
    fastinput;
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    // startTime = clock();

    
    
    // cout << "RunTime: " << fixed << setprecision(5) << getCurrentTime() << 's' << nl;
    return 0;
}