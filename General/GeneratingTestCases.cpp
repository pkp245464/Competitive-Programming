#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define phb push_back
#define phf push_front
#define ppf pop_front
#define ppb pop_back
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	srand(time(NULL));
	int t=rand()%1+1;
	cout<<t<<nl;
	while(t--) {
		int n=rand()%5+1;
		cout<<n<<nl;
		for(int i=0;i<n;i++) {
			cout<<(rand()%6+1)<<" ";
		}
		cout<<nl;
	}
	return 0;
}

