#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class JobSequencing {
public:
	char id;
	int dead;
	int profit;
	bool static comparison(JobSequencing a,JobSequencing b) {
		return (a.profit>b.profit);
	}
	void scheduling(JobSequencing arr[],int n) {
		sort(arr,arr+n,comparison);
		int result[n];
		bool slot[n];
		for(int i=0;i<n;i++) {
			slot[i]=false;
		}
		for(int i=0;i<n;i++) {
			for(int j=min(n,arr[i].dead)-1;j>=0;j--) {
				if(slot[j]==false) {
					result[j]=i;
					slot[j]=true;
					break;
				}
			}
		}
		for(int i=0;i<n;i++) {
			if(slot[i]) {
				cout<<arr[result[i]].id<<" ";
			}
		}
	}
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	JobSequencing *p=new JobSequencing();
	JobSequencing arr[]={ {'A',2,100},
						  {'B',1,19},
						  {'C',2,27},
						  {'D',1,25},
						  {'E',3,15} };
	int n=sizeof(arr)/sizeof(arr[0]);
	p->scheduling(arr,n);
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define phb push_back
#define phf push_front
#define ppf pop_front
#define ppb pop_back
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
	int id;
	int dead;
	int profit;
	bool static comparator(Solution a,Solution b) {
		return (a.profit>b.profit);
	}
	pair<int,int> JobScheduling(Solution arr[],int n) {
		sort(arr,arr+n,comparator);
		int maxi=arr[0].dead;
		for(int i=1;i<n;i++) {
			maxi=max(maxi,arr[i].dead);
		}
		int slot[maxi+1];
		for(int i=0;i<=maxi;i++) {
			slot[i]=-1;
		}
		int cntJobs=0,jobProfit=0;
		for(int i=0;i<n;i++) {
			for(int j=arr[i].dead;j>0;j--) {
				if(slot[j]==-1) {
					slot[j]=i;
					cntJobs++;
					jobProfit+=arr[i].profit;
					break;
				}
			}
		}
		return make_pair(cntJobs,jobProfit);
	}
};
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n=4;
	Solution arr[n]={ {1,4,20},{2,1,10},{3,2,40},{4,2,30} };
	Solution *p=new Solution();
	pair<int,int>ans=p->JobScheduling(arr,n);
	cout<<ans.first<<" "<<ans.second<<nl;
	return 0;
}
*/

