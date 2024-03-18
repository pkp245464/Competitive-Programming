#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Activity {
public:
	int start,finish;
	bool static ActivityCompare(Activity s1,Activity s2) {
		return (s1.finish<s2.finish);
	}
	void maxSelection(Activity arr[],int n) {
		sort(arr,arr+n,ActivityCompare);
		int i=0;
		cout<<"("<<arr[i].start<<","<<arr[i].finish<<")"<<nl;
		for(int j=1;j<n;j++) {
			if(arr[j].start>=arr[i].finish) {
				cout<<"("<<arr[j].start<<","<<arr[j].finish<<")"<<nl;
				i=j;
			}
		}
	}
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Activity arr[]={ {5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
	int n=sizeof(arr)/sizeof(arr[0]);
	Activity *p=new Activity();
	p->maxSelection(arr,n);
    return 0;
}

