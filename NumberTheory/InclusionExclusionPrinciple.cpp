/*
//Inclusion-Exclusion principle

n(A U B) = n(A) + n(B) – n(A ∩ B)
n(A U B U C) = n(A) + n(B) + n(C) - n(A ∩ B) - n(B ∩ C) - n(A ∩ C) + n(A ∩ B ∩ C)

n = 20
a = {2,3,5}
a1 = 2 : 2,4,6,8,10,12,14,16,18,20 => 10 another ways: calculate direct (20 / 2 = 10)
a2 = 3 : 3,6,9,12,15,18 (same: 20 / 3 = 6) 
a3 = 5 : 5,10,15,20 (20 / 5 = 4)
{Note: n is divisble a & b then n also divisible by their product a * b}
n % a == 0
n % b == 0
n % (a * b) == 0
n = 6
6 / 2 = 3
6 / 3 = 2
6 / (2 * 3) = 6
total count = 10 + 6 + 4 = 20 : wrong because some number like 6 divide by 2 and 3 (we count 2 but it 1)
here we count the duplicate number.
All duplicate pair: common between 2 & 3 (6,12,18)
								   2 & 5 (10,20)
								   3 & 5 (15)
								   2 & 3 & 5 (empty)	
correct answer: 14
n(A U B U C) = n(A) + n(B) + n(C) - n(A ∩ B) - n(B ∩ C) - n(A ∩ C) + n(A ∩ B ∩ C)
			 = 10 + 6 + 4 - 3 - 1 - 2 - 0
			 = 20 - 6
			 = 14

//converting into code form
n(A U B U C) = n(A) + n(B) + n(C) - n(A ∩ B) - n(B ∩ C) - n(A ∩ C) + n(A ∩ B ∩ C)
for finding 
n(A) can be written as: n / a (actually this is the direct method to calculate)
similiarly n(B) = n / b and n(C) = n / c
{Note: n is divisble a & b then n also divisible by their product a * b}
n(A ∩ B) = n / a * b
n(B ∩ C) = n / b * c
n(C ∩ A) = n / c * a
n(A ∩ B ∩ C) = n / a * b * c

n(a + b + c) = (n / a) + (n / b) + (n / c) - (n / ab) - (n / bc) - (n / ca) - (n / abc)

Problem: -> is now,how can pick the combination of (a,b,c):-> n/a,n/b,n/c,n/ab,n/ba,n/ca,n/abc
using bit masking we can pick the combination easily

a b c (pick the combination)
0 0 0 () (ignore this case start from 1 to 2 ^ n)
0 0 1 (c)
0 1 0 (b)
0 1 1 (bc)
1 0 0 (a)
1 0 1 (ac)
1 1 0 (ab)
1 1 1 (abc)

sudo code for combination
for(int mask = 1; mask < (1 << n); i++) {
	for(int i = 0; i < n; i++) {
		if((1 << i) & mask) cout << 1 << " ";
		else cout << " ";
	}
	cout << nl;
}

Problem: -> how can know when we subtract and add which are given in formula
n(a + b + c) = (n / a) + (n / b) + (n / c) - (n / ab) - (n / bc) - (n / ca) - (n / abc)
Sol - when product formed number is odd then add and for even subract means when count denominator number

even: (+)n/a, (+) n/b, (+)n/c, (+)n/abc :: because denominator count is odd
odd : (-)n/ab, (-)n/ab, (-)n/bc, (-)n/ca :: because denominator count is even 

-> for complete imlementation see the below code
*/
  

/*
//based on Inclusion-Exclusion principle
//=> https://cses.fi/problemset/task/2185/

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
    ll n;
    int k;
    cin >> n >> k;
    vector<ll>primes(k);
    for(int i = 0; i < k; i++) {
        cin >> primes[i];
    }
    vector<ll>cntDivisiors(k + 1);
    for(int mask = 1; mask < (1 << k); mask++) {
        int curdivisiors = 0;
        ll tmp = n;
        for(int i = 0; i < k; i++) {
            if((1 << i) & mask) {
                curdivisiors++;
                tmp /= primes[i];
            }
        }
        // int curdivisiors = __builtin_popcount(mask); //or for counting number of curdivisiors
        cntDivisiors[curdivisiors] += tmp;
    }
    ll ans = 0;
    for(int i = 1; i <= k; i++) {
        if(i % 2 == 0) {
            ans -= cntDivisiors[i];
        }
        else {
            ans += cntDivisiors[i];
        }
    }
    cout << ans << nl;
    return 0;
}
I/P:
20 2
2 5
O/P: 12 {2,4,5,6,8,10,12,14,15,16,18,20}
*/