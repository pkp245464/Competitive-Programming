/*
Given an array A of size N.You have to find the minimal non-negative element that is not present in the array.
That number is commonly called the MEX (minimal excluded).
mex({0,1,2,4,5}) => 3
mex({0,1,2,3,4}) => 5
mex({1,2,3,4,5}) => 0
*/

//TC: O(NlogN)
int mex(vector<int>const&a) {
    set<int>st(a.begin(),a.end());
    int ans = 0;
    while(st.count(ans)) {
        ++ans; 
    }
    return ans;
}
/*
If you need to compute the MEX over and over, e.g. because your array keeps changing, then it is not effective. 
*/
//TC: O(N)
constexpr int MAX_N = 1e6;
int mex(vector<int>const&a) {
    static bool used[MAX_N] = {0};
    for(int x : a) {
        if (x <= MAX_N)
            used[x] = true;
    }
    int ans = 0;
    while(used[ans]) {
        ++ans;
    }
    for(int x : a) {
        if(x <= MAX_N) {
            used[x] = false;
        }
    }
    return ans;
}

/*
compute the new MEX of the array after each such update
Precomputation TC: O(NlogN)
Find the mex Tc: O(1)
Update TC: O(logN)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Mex {
private:
    map<int,int>freq;
    set<int>missing_numbers;
    vector<int>arr;
public:
    Mex(vector<int>const& arr) : arr(arr) {
        for(int i = 0; i <= arr.size(); i++) {
            missing_numbers.insert(i);
        }
        for(int x : arr) {
            ++freq[x];
            missing_numbers.erase(x);
        }
    }
    int mex() {
        return *missing_numbers.begin();
    }
    void update(int ind,int val) {
        if(--freq[arr[ind]] == 0) {
            missing_numbers.insert(arr[ind]);
        }
        arr[ind] = val;
        ++freq[val];
        missing_numbers.erase(val);
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>a = {2,1,0,4,5};
    Mex *p = new Mex(a); //TC: O(NlogN)
    cout << p->mex() << nl; //TC: O(1)
    p->update(4,3); //TC: O(logN)
    cout << p->mex() << nl;
    return 0;
}

/*
Q.1) https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c
I/N: n = 4
	arr[i] = {1,1,0,2}
O/P: 0,0,2,3

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int N = 2e6;
vector<int>cnt(N);
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,ind = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        while(cnt[ind]) {
            ind++;
        }
        cout << ind << nl;
    }
    return 0;
}

//Or
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,ind = 0;
    cin >> n;
    set<int>st;
    for(int i = 0; i <= n; i++) {
        st.insert(i);
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(st.find(x) != st.end()) {
            st.erase(x);
        }
        cout << *st.begin() << nl;
    }
    return 0;
}
*/