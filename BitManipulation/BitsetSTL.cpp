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
	// 16 = 00000000 00000000 00000000 00010000;
	
	//int x = __builtin_clz(16); //count leading zeros
	//cout << x << nl; //O/P: 27
	
	//int y = __builtin_ctz(x); //count trailing zeros
	//cout << y << nl; //O/P: 4 
	/* 	(bonus - how many times number is divisible by 2)
		// or count through __builtin_ctz(n) function give same result
		// n = 32 -> 2 * 2 * 2 * 2 = 32 -> ans = 4
		// n = 12 -> 2 * 2 * 3 // ans = 2
		// n = 11 -> ans = 0
		
		int n,cnt = 0;
		while(n % 2 == 0) {
			cnt++;
			n /= 2;
		}
	*/
	
	//int a = __builtin_popcount(16); // count for int set bit
	//cout << z << nl; //O/P: 1
	
	//long long b =  __builtin_popcountll // count for long long set bit
	
	// //Create Bitset
    // bitset<4>a;
    // cout << a << nl; // 0000
    // a[0] = 1;
    // a[1] = 0;
    // a[2] = 1;
    // a[3] = 1;
    // cout << a << nl; // O/P: 1101
    // //Or
    // for(int i = 0; i < a.size(); i++) {
    //     cout << a[i] << " \n"[i + 1 == a.size()]; //O/P: 1 0 1 1
    // }
    
    // //Integer to biset and vice-versa
    // bitset<8>a(7); // creating bitsetsize with 8 value is equal to 7
    // cout << a[0] << " " <<  a << nl; //O/P: 1 <-> 00000111 = 7
    // int n = (int)a.to_ulong(); // bitset to long by default we can use typecasting to convert int type 
    // cout << n << nl;

    // // String to bitset
    // string s = "1010110100"; 
    // bitset<10>a(s);
    // cout << a[0] << n; // O/P: 0 
    // string str = a.to_string(); 
    // cout << str << nl; // O/P:  1010110100
    // cout << a.count() << nl; // O/P: 5 :->Count no of ones

    // // Basic operations
    // bitset<4>a(string("0101")); 
    // bitset<4>b(string("1010")); 
    // cout << (a & b) << nl;   // O/P: 0000 
    // cout << (a | b) << nl;   // O/P: 1111 
    // cout << (a ^ b) << nl;   // O/P: 1111 
    // cout << (~a) << nl;      // O/P: 1010 
    // cout << (a << 1) << nl;  // O/P: 1010 
    // cout << (b >> 1) << nl;  // O/P: 0101 
    
    // // istringstream 
    // string str = "1010110100"; 
    // istringstream stream(str); 
    // bitset<2> s1; 
    // bitset<6> s2; 
    // stream >> s1; // store the first 2 digit towards right
    // cout << s1 << nl; // O/P: 10 
    // stream >> s2; // store from 2nd index to 6 digit towards right 
    // cout << s2 << nl; // O/P: 101101 
    
    // // Check if any bit is set
    // bitset<4>a1(string("1010")); 
    // bitset<4>b1(string("0000")); 
    // cout << a1.any() << nl; // O/P: true 
    // cout << b1.any() << nl; // O/P: false 
    // // Check if none of the bits are set
    // cout << a1.none() << nl; // O/P: false 
    // cout << b1.none() << nl; // O/P: true 
    
    // // Check if all bits are set
    // bitset<4>a(string("1111")); 
    // cout << a.all() << nl; //O/P: True

    // //Flip all or any particular bit
    // bitset<4>a(string("0000")); 
    // cout << a.flip() << nl; // 0101 // if index is not given then work like ~(NOT) 
    // cout << a.flip(1) << nl; // 0111  // flip index one from right

    // // Reset all or any particular bit
    // bitset<4>a(string("1010")); 
    // cout << a.reset(1) << nl; //O/P: 1000 
    // cout << a.reset() << nl; //O/P: 0000

    // // Set all or any particular bit
    // bitset<4>a(string("1010"));
    // cout << a.set(0) << nl; // 1011
    // cout << a.set() << nl; // 0000  
	
    return 0;
}

/*
int singificant_bit_position(int x) {
    int pos = 0;
    while (x != 0) {
        x /= 2; //x = x >> 1;
        pos++;
    }
    return pos;
}
*/