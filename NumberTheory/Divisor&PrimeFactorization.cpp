#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//TC - O(n)
void primeFactors(int n) {
	for(int i = 2; i <= n; i++) {
		while (n % i == 0) {
			cout << i << " " ;
			n = n / i ;
		}
	}
	cout << nl;
}
//TC - O(sqrt(N))
void primeFactor(ll n) {
    vector<ll>prime;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                prime.push_back(i);
                n = n / i ;
            }
        }
    }
    if(n > 1) {
    	prime.push_back(n);
    }
    for(auto it : prime) {
        cout << it << " ";
    }
    cout << nl;
}
//TC - O(sqrt(N))
void allDivisor(ll n) {
    vector<ll>div;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
			// cout << i << " * " << n / i << nl; //n = 36 O/P: {(1,36),(2,18),(3,12),(4,9),(6,6)} // print the duplicate divisor like(6,6) 
            div.push_back(i);
            if(i * i != n) { // to avoid the duplicate divisor: 36 = 6 * 6 
				div.push_back(n / i);
			}
        }
    }
    sort(div.begin(),div.end());
    for(auto it : div) {
        cout << it << " ";
    }
    cout << nl;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ll n = 36;
    primeFactor(n); //n = 36 : 2 2 3 3  
	allDivisor(n); //n = 36: 1 2 3 4 6 9 12 18 36 
    return 0;
}

/*
// sum of divisior up to N
n = 5
1: 1 => 1
2: 1,2 => 3
3: 1,3 => 4
4: 1,2,4 => 7
5: 1,5 => 6
sum = 1 + 3 + 4 + 7 + 6 => 21 Ans.

//TC - O(n)
int sumOfDivisor(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += (n / i) * i;
		return sum;
	}
}

//TC - sqrt(N)
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
const int MOD = 1e9 + 7;
ll BEI(ll a,ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n,ans = 0;
    cin >> n;
    for(ll i = 1,j; i <= n; i = j) {
        ll q = n / i;
        j = n / q + 1;
        ll x = ((((j % MOD) * ((j - 1) % MOD)) % MOD) * BEI(2,MOD - 2)) % MOD;
        ll y = ((((i % MOD) * ((i - 1) % MOD)) % MOD) * BEI(2,MOD - 2)) % MOD;
        ll z = (x - y + MOD) % MOD;
        ans = (ans + (q % MOD) * z) % MOD;
    }
    cout << ans << nl;
    return 0;
}

Q.1) https://cses.fi/problemset/task/1082/
Sol - https://usaco.guide/problems/cses-1082-sum-of-divisors/solution
*/