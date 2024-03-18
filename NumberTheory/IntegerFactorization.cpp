#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//trial division
vector<ll> fun(ll n) {
    vector<ll>factorization;
    for(ll d = 2; d * d <= n; d++) {
        while(n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if(n > 1) {
        factorization.push_back(n);
    }
    return factorization;
}
//wheel factorization
vector<ll> wheelFactorization(ll n) {
    vector<ll>factorization;
    while(n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for(ll d = 3; d * d <= n; d += 2) {
        while(n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if(n > 1) {
        factorization.push_back(n);
    }
    return factorization;
}

//using prime techniques
int N = 1e5 + 3;
vector<bool>sieve(N);  
vector<ll> primes;
void createSieve() {
    for(int i = 2; i <= N; i++) {
        sieve[i] = true;
    }
    for(int i = 2; i * i <= N; i++) {
        if(sieve[i] == true) {
            for(int j = i * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
    }
    for(int i = 2; i <= N; i++) {
        if(sieve[i]) primes.push_back(i);
    }
}
vector<ll> sieveFactorization(ll n) {
    createSieve();
    vector<ll> factorization;
    for(ll d : primes) {
        if(d * d > n) {
            break;
        }
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1) {
        factorization.push_back(n);
    }
    return factorization;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n = 463984; //2 2 2 2 47 617 
    vector<ll>ans = trial_division3(n);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}


/*
//using factrize_pollard_rho

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T,typename U,typename V>
T modexp(T base,U exp,V mod) {
    if(exp == 0) {
        return 1;
    }
    base %= mod;
    if(base <= 1) {
        return base;
    }
    T res = 1;
    while(exp) {
        if(exp & 1) {
            res = (1LL * res * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp >>= 1;
    }
    return res;
}
template <typename T>
bool miller_rabin(T number) {
    if(number < 2) {
        return 0;
    }
    // given base_set ensures correctness for numbers in range[2,1e18]
    vector<T>base_set{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; //refer wikipedia for determinstic range and numbers in base_set
    long long d = number - 1;
    int r = __builtin_ctzll(d);
    d >>= r;

    bool not_prime;
    long long val;

    // for every element in base, the test must find the number to be a prime.
    for (long long base : base_set) {
        // ensure number used for primality check lies in range [2,number-2] so it satisfies the mathematical reqiurements
        if(base < 2 || base > number - 2) {
            continue;
        }
        not_prime = true;
        val = modexp(base, d, number);
        if(val == 1 || val == number - 1) {
            continue;
        }
        for(int i = 1; i < r; i++) {
            val = (val * val) % number;
            if(val == number - 1) {
                not_prime = false;
                break;
            }
        }
        if(not_prime) {
            return false;
        }
    }
    return true;
}
template <typename T>
T fun(T num, T mod) {
    T val = modexp(num,2,mod) + 1;
    if(val >= mod) {
        val -= mod;
    }
    return val;
}
template <typename T>
T pollard_rho(T num) {
    if(num < 2) {
        return num;
    }
    if(num % 2 == 0) {
        return 2;
    } 

    T sq = sqrt(num) + 2;

    T slow = uniform_int_distribution<int>(3, sq)(rng);
    T fast = slow;
    T gcd = 1;
    int max_iter = 500;

    while(gcd == 1 && max_iter--) {
        slow = fun(slow,num);
        fast = fun(fun(fast,num),num);
        gcd = __gcd(abs(slow - fast),num);

        if(gcd != 1) {
            if(gcd == num) {
                slow = uniform_int_distribution<int>(3,sq)(rng);
                fast = slow;
                gcd = 1;
            }
            else {
                break;
            }
        }
    }
    return gcd;
} 
template<typename T>
vector<pair<T,int>> factorize(T num) {
    vector<pair<T,int>> factors;

    while(num > 1) {
        T factor = num;
        while(!miller_rabin(factor)) {
            factor = pollard_rho(factor);
        }
        int cnt = 1;
        num /= factor;
        while(num % factor == 0) {
            num /= factor;
            cnt++;
        }
        factors.push_back({factor, cnt});
    }
    return factors;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 463984;
    vector<pair<int,int>>ans = factorize(n);
    for(auto it : ans) {
        cout << it.first << " " << it.second << nl;
    }
    return 0;
}
*/