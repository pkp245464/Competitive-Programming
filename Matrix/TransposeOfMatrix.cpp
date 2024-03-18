#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
const int M=4;
const int N=4;
	
void transpose(int arr[M][N]) {
	for(int i=0;i<M;i++) {
		for(int j=i+1;j<N;j++) {
			swap(arr[i][j],arr[j][i]);
		}
	}
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<nl;
	}
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int arr[M][N]{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	transpose(arr);
	return 0;
}
//Second Method
/*
void transpose(int arr[M][N]) {
	int temp[M][N];
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			temp[i][j]=arr[j][i];
		}
	}
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			arr[i][j]=temp[j][i];
		}
	}
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			cout<<arr[j][i]<<" ";
		}
		cout<<nl;
	}
}
*/

