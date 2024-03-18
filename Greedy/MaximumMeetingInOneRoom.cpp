#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void maxMeeting(vector<int>&start,vector<int>&finish) {
	int n=start.size();
	pair<int,int>arr[n+1];
	for(int i=0;i<n;i++) {
		arr[i].first=finish[i];
		arr[i].second=i;
	}
	sort(arr,arr+n);
	int timeLimit=arr[0].first;
	vector<int>ans;
	ans.push_back(arr[0].second+1);
	for(int i=1;i<n;i++) {
		if(start[arr[i].second]>=timeLimit) {
			ans.push_back(arr[i].second+1);
			timeLimit=arr[i].first;
		}
	}
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<"->";
		cout<<"("<<start[ans[i]-1]<<","<<finish[ans[i]-1]<<")"<<nl;
	}
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
	/*vector<int>start{1,3,0,5,8,5}; //Answer->1->(1,2)
											   2->(3,4)
											   4->(5,7)
											   5->(8,9)
	vector<int>finish{2,4,6,7,9,9};*/
	vector<int>start{75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
	vector<int>finish{112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 };
	maxMeeting(start,finish);
    return 0;
}