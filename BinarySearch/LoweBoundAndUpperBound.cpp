#include<bits/stdc++.h>  
using namespace std;
#define lli long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {1,4,4,4,4,9,9,9,10,11};
	cout<<arr.size()<<nl;

	int target1 = 4;
	int ind1 = lower_bound(arr.begin(),arr.end(),target1) - arr.begin();
	int ind2 = upper_bound(arr.begin(),arr.end(),target1) - arr.begin();
	cout<<ind1<<" "<<ind2<<nl;

	int target2 = 11;
	int ind3 = lower_bound(arr.begin(),arr.end(),target2) - arr.begin();
	int ind4 = upper_bound(arr.begin(),arr.end(),target2) - arr.begin();
	cout<<ind3<<" "<<ind4<<nl;

	int target3 = 1;
	int ind5 = lower_bound(arr.begin(),arr.end(),target3) - arr.begin();
	int ind6 = upper_bound(arr.begin(),arr.end(),target3) - arr.begin();
	cout<<ind5<<" "<<ind6<<nl;

    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
1.) Find the first Occurence of a X in a sorted array. if does not exits,
	print -1

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {1,4,4,4,4,9,9,9,10,11};
	int target = 9; 
	int ind = lower_bound(arr.begin(),arr.end(),target) - arr.begin();
	if(ind != arr.size() && arr[ind] == target) {
		cout<<"Position: "<<ind<<nl;
	}
	else {
		cout<<"-1"<<nl;
	}
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
2.) Find the last Occurence of a X in a sorted array. if does not exits,
	print -1

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {1,4,4,4,4,9,9,9,10,11};
	int target = 9; 
	int ind = upper_bound(arr.begin(),arr.end(),target) - arr.begin();
	ind--;
	if(ind >= 0 && arr[ind] == target) {
		cout<<"Position: "<<ind<<nl;
	}
	else {
		cout<<"-1"<<nl;
	}
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
3.) Find the largest number, smaller than X in a sorted array. if no 
	number exits print -1.

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {1,4,4,4,4,9,9,9,10,11};
	int target = 9; 
	int ind = lower_bound(arr.begin(),arr.end(),target) - arr.begin();
	ind--;
	if(ind >= 0) {
		cout<<"Number: "<<arr[ind]<<nl;
	}
	else {
		cout<<"-1"<<nl;
	}
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
4.) Find the smallest number, greater than X in a sorted array. if no 
	number exits print -1.
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr = {1,4,4,4,4,9,9,9,10,11};
	int target = 9; 
	int ind = upper_bound(arr.begin(),arr.end(),target) - arr.begin();
	if(ind < arr.size()) {
		cout<<"Number: "<<arr[ind]<<nl;
	}
	else {
		cout<<"-1"<<nl;
	}
    return 0;
}
*/