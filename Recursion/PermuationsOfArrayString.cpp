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
    vector<char>arr1 = {'A','B','C'};
    next_permutation(arr1.begin(),arr1.end());
    for(int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << nl;
    vector<int>arr2 = {1,2,3};
    prev_permutation(arr2.begin(),arr2.end());
    for(int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}
/*
1 2 3 ||| A B C
1 3 2 ||| A C B  
2 1 3 ||| B A C  
2 3 1 ||| B C A  
3 2 1 ||| C A B  
3 1 2 ||| C B A 
*/

/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------///
void display(vector<int>&arr,int n) {
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
void permuations(vector<int>&arr,int n) {
	sort(arr.begin(),arr.end());
	do {
		display(arr,n); 
	} while(next_permutation(arr.begin(),arr.end()));
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>arr{1,2,3};
	int n=arr.size();
	permuations(arr,n); 
    return 0;
}
*/

//Second Method (Using swap function)
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
	void recPermute(int ind,vector<int>&nums,vector<vector<int>>&ans) {
		if(ind==nums.size()) {
			ans.push_back(nums);
			return;
		}
		for(int i=ind;i<nums.size();i++) {
			swap(nums[ind],nums[i]);
			recPermute(ind+1,nums,ans);
			swap(nums[ind],nums[i]);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recPermute(0,nums,ans);
        return ans;
    }
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>arr{1,2,3};
	Solution *p=new Solution();
	vector<vector<int>>ans=p->permute(arr);
	for(int i=0;i<ans.size();i++) {
		for(int j=0;j<ans[i].size();j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<nl;
	}
    return 0;
}
O/p-
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2 
*/
//Third method
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
	void recPermute(vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,int freq[]) {
		if(ds.size()==nums.size()) {
			ans.push_back(ds);
			return;
		}
		for(int i=0;i<nums.size();i++) {
			if(!freq[i]) {
				ds.push_back(nums[i]);
				freq[i]=1;
				recPermute(ds,nums,ans,freq);
				freq[i]=0;
				ds.pop_back();
			}
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) {
        	freq[i]=0;
        }
        recPermute(ds,nums,ans,freq);
        return ans;
    }
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>arr{1,2,3};
	Solution *p=new Solution();
	vector<vector<int>>ans=p->permute(arr);
	for(int i=0;i<ans.size();i++) {
		for(int j=0;j<ans[i].size();j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<nl;
	}
    return 0;
}
/*
O/p-
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2 
*/
//|----------------------------------------------------------------------------------|
//|----------------------------------------------------------------------------------|
//|----------------------------------------------------------------------------------|



//Get from specific position permuations
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
	string getPermutation(int n,int k) {
		int fact=1;
		vector<int>nums;
		for(int i=1;i<n;i++) {
			fact=fact*i;
			nums.push_back(i);
		}
		nums.push_back(n);
		string ans="";
		k=k-1;
		while(true) {
			ans=ans+to_string(nums[k/fact]);
			nums.erase(nums.begin()+k/fact);
			if(nums.size()==0) {
				break;
			}
			k=k%fact;
			fact=fact/nums.size();
		}
		return ans;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p=new Solution(); 
	cout<<p->getPermutation(3,3);
    return 0;
}
I/p- (3,3)
O/p-
213

Explain 
1."123"
2."132"
3."213"
4."231"
5."312"
6."321"
*/