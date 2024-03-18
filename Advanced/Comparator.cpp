/*
// sort first element descending order and for second element sort ascending wise
bool comparator(pair<int,int>a,pair<int,int>b){
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}
I/P:
7 2
4 10
4 10
4 5
3 20
2 1
2 1
1 10
O/P:
4 5
4 10
4 10
3 20
2 1
2 1
1 10
2
*/	

//Sort three element if two element equal then sort according alphabetically
//vector<pair<string,pair<string,long long>>>vp;
static bool comprator(pair<string,pair<string,long long>>a,pair<string,pair<string,long long>>b) {
	if(a.first == b.first) {
		if(a.first > b.first) {
			return true;
		}
		else {
			return false;
		}
	}
	else if(a.second.second > b.second.second) {
		return true;
	}
	else {
		return false; 
	} 
}


//Sort 2D array according to specific element 
//Ascending or Descending Order
/*
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
static bool comprator(vector<int>&a,vector<int>&b) {
    if(a[1] < b[1]) return true;
    return false;
}
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>>arr = {{7,4,10},{3,9,30},{2,5,20},{4,6,40},{8,4,50}};
    sort(arr.begin(),arr.end(),comprator);
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<nl;
    }
    return 0;
}
*/


/*

//Comparator Using Sort Function
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//According To the First Element
bool comprator1(pair<int,int>a,pair<int,int>b) {
	// Descending Order   
	//if(a.first > b.first) return true; //Or if(a > b) return true;  //Statement 1->return false
	//else return false; //Statement 2->return true
	//(if we apply statement 1 and statement 2  then work like Ascending Order)

	//Ascending Order
	if(a.first < b.first) return true; // Or if(a < b) return true;   //Statement 1->return false
	else return false;  //Statement 2->return true
	//(if we apply statement 1 and statement 2  then work like Descending Order)
}

//According To the Second Element
bool comprator2(pair<int,int>a,pair<int,int>b) {
	// Descending Order 
	if(a.second > b.second) return true;  //Statement 1->return false
	else return false;  //Statement 2->return true
	//(if we apply statement 1 and statement 2  then work like Ascending Order)
	
	//Ascending Order
	//if(a.second < b.second) return true;   //Statement 1->return false
	//else return false;  //Statement 2->return true  
	//(if we apply statement 1 and statement 2  then work like Descending Order)
}
//Special Case
//Sort According to Second Element Ascending Order
//It is Stable
//I/P: 1,5,0,5
//O/P: 0 1 5 5 Not Stable 
//O/P: 1 0 5 5 Stable
static bool comparator(pair<int,int>a,pair<int,int>b) {
	if(a.second == b.second) {
		return a.first > b.first;
	}
	else return (a.second < b.second);
}

int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n = 9;
	vector<pair<int,int>>arr = {{4,3},{5,5},{1,2},{5,3},{1,6},{7,2},{8,5},{3,0},{9,0}};
	//sort(arr.begin(), arr.end());  // Work Like Comparator 1 According Ascending Order First Element
	sort(arr.begin(), arr.end(),comprator2);		
	for(int i = 0; i < n; i++) {
		cout<<arr[i].first<<" "<<arr[i].second<<nl;
	}
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/



// Normal Soring Without Comparator

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
	int n = 5;
	vector<int>arr = {9,3,2,7,4};
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			//  if(arr[i] > arr[j)--->Ascending Order  
			//  if(arr[i] < arr[j)--->Descending Order  
			if(arr[i] > arr[j]) {   
				swap(arr[i],arr[j]);
			}
		}
	}		
	for(int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	// Ans: 2 3 4 7 9 
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*

// Same Things Using Comparator

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
bool comprator(int a,int b) {
	if(a > b) return true;
	else return false;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n = 5;
	vector<int>arr = {9,3,2,7,4};
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(comprator(arr[i],arr[j])) {
				swap(arr[i],arr[j]);
			}
		}
	}		
	for(int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	// Ans: 2 3 4 7 9 
    return 0;
}

*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*

// Pair Sorting Using Comparator

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
//Sort According To Pair First Element
bool comprator(pair<int,int>a,pair<int,int>b) {
	if(a > b) return true;
	else return false;
}
//Sort According to Pair Second Element
bool comprator(pair<int,int>a,pair<int,int>b) {
	if(a.second > b.second) return true;
	else return false;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n = 9;
	vector<pair<int,int>>arr = {{4,3},{5,5},{1,2},{5,3},{1,6},{7,2},{8,5},{3,0},{9,0}};
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(comprator(arr[i],arr[j])) {
				swap(arr[i],arr[j]);
			}
		}
	}		
	for(int i = 0; i < n; i++) {
		cout<<arr[i].first<<" "<<arr[i].second<<nl;
	}
    return 0;
}
*/
