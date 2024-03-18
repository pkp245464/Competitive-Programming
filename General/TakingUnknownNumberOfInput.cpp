#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>arr;
	int input;
	while(cin>>input) {
		arr.push_back(input);
	}
	cout<<"Total Input Taken By User: "<<arr.size()<<nl;
	for(auto it:arr) {
		cout<<it<<" ";
	}
    return 0;
}
