#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a = 3,b = 9,c = 15;
    //------------ Parameters-------------body----------call---  
    int temp = [](int x,int y,int z){return x + y + z;}(a,b,c);  
    cout <<  temp << nl;
		
	//Or	
	auto mulplication = [](int x,int y,int z){return x * y * z;};  
    cout << mulplication(3,3,3) << nl;
	
	//check all the elements are equal in vector
	vector<int>a = {3,3,3,3,3};
	bool flag = all_of(a.begin(),a.end(),[&](int x){return x == a[0];});
	//OR: bool flag = all_of(a.begin(),a.end(),[a](int x){return x == a[0];});

	//Check all number in vector is postive or not using all_of & lambda (return true or false)
    vector<int>arr1 = {9,3,5,7,2,1,6,4,8};
    cout << all_of(arr1.begin(),arr1.end(),[](int x){return x > 0;}) << nl;
    
    //Check any number is negative or not using any_of & lambda (return true or false)
    vector<int>arr2 = {9,3,5,7,2,1,-6,4,8};
    cout << any_of(arr2.begin(),arr2.end(),[](int x){return x < 0;}) << nl;

    //Check none of the number is greater than 9 using none_of & lambda (return true)
    vector<int>arr3 = {9,3,5,7,2,1,-6,4,8,10};
    cout << any_of(arr3.begin(),arr3.end(),[](int x){return x > 9;}) << nl;
    return 0;
}



