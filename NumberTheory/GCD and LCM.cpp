#include<bits/stdc++.h>
using namespace std;  
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//36 = 2 * 2 * 3 * 3
//60 = 2 * 2 * 3 * 5  
//gcd = 2 * 2 * 3 = 12

//Naive Approach //Tc: O(min(a,b))
int gcd(int a, int b) {
    int ans = min(a, b);
    while(ans > 0) {
        if(a % ans == 0 && b % ans == 0) {
            break;
        }
        ans--;
    } 
    return ans;
}
//Using Euclidean Algorithm // TC: O(log(min(a,b)))
int gcd(int a,int b) {
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }
    if(a == b) {
        return a;
    }
    if(a > b) {
        return gcd(a - b,b);
    }
    else {
        return gcd(a,b - a);
    } 
}
//Optimizing using division // TC: O(log(min(a,b)))
// recursion method of gcd
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a % b);
}
int lcm(int a,int b) {
    return (a * b) / gcd(a,b);
}
// iterative method of gcd
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}
//Extended Euclidean Algorithm: ax + by = gcd(a,b)
int gcdExtended(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //Calculate GCD
    //cout<<__gcd(a,b)<<nl;
    int a = 3,b = 4;
    cout<<lcm(a,b)<<nl;
    
    //Calculate LCM
    int lcm = (a / __gcd(a,b)) *b;
    cout << lcm << nl;
	
	// gcd(a,b) = gcd(a,abs(a - b));
    return 0;
}