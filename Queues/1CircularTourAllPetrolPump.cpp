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
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
class PetrolPump {
public:
	int petrol;
	int distance;
};
int printTour(PetrolPump arr[],int n) {
	int start=0;
	int end=1;
	int curr_petrol=arr[start].petrol-arr[start].distance;
	while(end!=start || curr_petrol<0) {
		while(curr_petrol<0 && start!=end) {
			curr_petrol-=arr[start].petrol-arr[start].distance;
			start=(start+1)%n;
			if(start==0){
				return -1;
			}		
		}
		curr_petrol+=arr[end].petrol-arr[end].distance;
		end=(end+1)%n;
	}
	return start;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	PetrolPump arr[]={{6,4},{3,6},{7,3}};
	int n=sizeof(arr)/sizeof(arr[0]);
	int start=printTour(arr,n);
	if(start==-1) cout<<"NO Solutions!!!"<<"\n";
	else cout<<"Start: "<<start<<"\n";
    return 0;
}
