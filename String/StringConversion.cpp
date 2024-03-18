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
	
	//string to number
	string s1 = "3921";
	string s2 = "123.81";
	
	stringstream cnt1(s1);  //cnt variable name type
	int n = 0;
	cnt1 >> n;
	cout << n << nl;
	
	stringstream cnt2(s2);
	float m = 0; 
	cnt2 >> m; 
	cout << m << nl;

	// number to string
	int x = 392781;
	ostringstream s; 
	s << x; 
	cout << s.str() << nl;  
	
	float y = 3927.81;
	ostringstream t;
	t << y; 
	cout << t.str() << nl;
	
    return 0;
}
//OR
/*
	string s1 = "3921";
	int a = stoi(s1); // for int dataType
	string s = "12345677895289";
    long long b = stoll(s); // for long long dataType
	
	int n = 392781;
	string s1 = to_string(n); // work for int,long long,float double dataType
*/
