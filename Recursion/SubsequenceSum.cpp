#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
vector<int>ds;
vector<int>ans;  
void subSequence(int ind,int n,vector<int>arr) {
	if(ind == n) {
		int sum = 0;
		for(auto it : ds) {
			sum += it;
			cout<<it<<" ";
		}
		ans.push_back(sum);
		cout<<nl;
		return;
	}
	ds.push_back(arr[ind]);
	subSequence(ind + 1,n,arr);
	ds.pop_back();
	subSequence(ind + 1,n,arr);
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>arr{5,2,1};  //O/p-> 0 1 2 3 5 6 7 8
	int ind = 0;
	int n = 3;
	subSequence(ind,n,arr);
	sort(ans.begin(), ans.end());
	for(auto it : ans) {
		cout<<it<<" ";
	}
	return 0;

}
//Best Method
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution
{
public:
	void fun(int ind,int sum,vector<int>&arr,int n,vector<int>&sumSet) {
		if(ind == n) {
			sumSet.push_back(sum);
			return;
		}
		fun(ind + 1,sum + arr[ind],arr,n,sumSet);
		fun(ind + 1,sum,arr,n,sumSet);
	}	
	vector<int> subsetSum(vector<int>&arr,int n) {
		vector<int>sumSet;
		fun(0,0,arr,n,sumSet);
		sort(sumSet.begin(), sumSet.end());
		return sumSet;
	}
};
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	Solution *p=new Solution();
	vector<int>arr{5,2,1}; //O/p-> 0 1 2 3 5 6 7 8
	int n = 3;
	vector<int>ans = p->subsetSum(arr,n);
 	for(auto it : ans)
 		cout<<it<<" ";
 	return 0;
}
*/
