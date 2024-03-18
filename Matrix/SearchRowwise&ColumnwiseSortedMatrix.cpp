#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define phb push_back
#define phf push_front
#define ppf pop_front
#define ppb pop_back
#define in insert
#define as assign
#define nle "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
const int M=4;
const int N=4;
void searchMatrix(int arr[M][N],int key) {
	int i=0,j=N-1;
	while(i<M && j>=0) {
		if(arr[i][j]==key) {
			cout<<"("<<i<<","<<j<<")"<<nle;
			return;
		}
		else if(arr[i][j]>key) {
			j--;
		}
		else {
			i++;
		}
	}
	cout<<"Key Not Found!!!"<<nle;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	//matrix sorted with row-wise & column-wise
	int arr[M][N]{{10,20,30,40},
				  {15,25,35,45},
				  {27,29,37,48},
				  {32,33,39,50}};
	int key=33;
	searchMatrix(arr,key);
	
	return 0;
}

