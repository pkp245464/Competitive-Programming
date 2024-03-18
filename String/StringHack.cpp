#include<bits/stdc++.h>
using namespace std;
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
	
	string s = "abcdefgh";  
	int l = 3,r = 7; // reverse // O/P: abgfedch
	l--;
    reverse(s.begin() + l,s.begin() + r);
	
	
    //string s = "PANKAJ";
    //int a = s.find('A'); // 1
    //int b = (int)(find(s.begin(), s.end(), 'A') - s.begin()); // 1
    //int c = s.find_first_of('A'); // 1
    //int d = s.find_last_of('A'); // 4
    //cout << a << " " << b << " " << c << " " << d << nl;
	
	//int a = s.find('S'); // -1
    //int b = (int)(find(s.begin(), s.end(), 'S') - s.begin()); // 6
    //int c = s.find_first_of('S'); // -1
    //int d = s.find_last_of('S'); // -1
    //cout << a << " " << b << " " << c << " " << d << nl;
	
    return 0;
}