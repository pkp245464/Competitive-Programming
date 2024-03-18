/*
Q.1) Given an array of n integers a[i].Let's say that the segment of this array a[l..r](1 ≤ l ≤ r ≤ n) 
is good if the sum of elements on this segment is at most s(the sum of elements on which does not exceed s).
Your task is to find the longest good segment.
Input-The first line contains integers n and s(1≤n≤1e5,1≤s≤1e18).The second line contains integers ai(1≤a[i]≤1e9).
->https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A //print the largest segment
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n" 
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n,sum;
    cin >> n >> sum;
    vector<ll>a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 0,x = 0,ans = 0;
    for(ll r = 0; r < n; r++) {
        x += a[r];
        while(x > sum) {
            x -= a[l];
            l++;
        } 
        ans = max(ans,r - l + 1); //ans += (r - l + 1) :for counting the number of segment according the question.
    }
    cout << ans << nl;
    return 0;
}


/*
Q.2) Given an array of n integers a[i].Let's say that the segment of this array a[l..r](1 ≤ l ≤ r ≤ n)is good if the 
sum of elements on this segment is at least s.Your task is to find the shortest good segment.
Input-The first line contains integers n and s(1≤n≤1e5,1≤s≤1e18).The second line contains integers ai(1≤a[i]≤1e9).
->https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B // shortest good segment
#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ll n,sum;
    cin >> n >> sum;
    vector<ll>a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 0,x = 0,ans = INT_MAX;
    for(ll r = 0; r < n; r++) {
        x += a[r];
        while(x  - a[l] >= sum) {
            x -= a[l];
            l++;
        }
        if(x >= sum) {
            ans = min(ans,r - l + 1);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << nl;
    return 0;
}
*/

/*
Q.3)  Given an array of n integers a[i].Let's say that the segment of this array a[l..r](1 ≤ l ≤ r ≤ n)is good
if the sum of elements on this segment is at most s.Your task is to find the number of good segments.
Input-The first line contains integers n and s(1≤n≤1e5,1≤s≤1e18).The second line contains integers ai(1≤a[i]≤1e9).

->https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/C // count the largest segment
*/

/*
Q-4) Given an array of n integers a[i].Let's say that the segment of this array a[l..r](1 ≤ l ≤ r ≤ n)is good 
if the sum of elements on this segment is at least s.Your task is to find the number of good segments.
Input-The first line contains integers n and s(1≤n≤1e5,1≤s≤1e18).The second line contains integers ai(1≤a[i]≤1e9).
->https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D // count the shortest good segment

#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ll n,sum;
    cin >> n >> sum;
    vector<ll>a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 0,x = 0,cnt = 0;
    for(ll r = 0; r < n; r++) {
        x += a[r];
        while(x >= sum) {
            x -= a[l];
            l++;
        }
        cnt += l;
    }
    cout << cnt << nl;
    return 0;
}
*/