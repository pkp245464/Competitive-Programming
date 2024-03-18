#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
	int value;
	int weight;
	bool static comparator(Solution a,Solution b) {
		double x=(double)a.value/(double)a.weight;
		double y=(double)b.value/(double)b.weight;
		return x>y;
	}
	double fractionKnapsack(int n,int W,Solution arr[]) {
		sort(arr,arr+n,comparator);
		int curWeight=0;
		double totalProfit=0.0;
		for(int i=0;i<n;i++) {
			if(curWeight+arr[i].weight<=W) {
				curWeight+=arr[i].weight;
				totalProfit+=arr[i].value;
			}
			else {
				int rem=W-curWeight;
				totalProfit+=(arr[i].value/(double)arr[i].weight)*rem;
				break;
			}
		}
		return totalProfit;
	}
};
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
	int n=3;
	int weight=50;
	Solution arr[n]={ {100,20},{60,10},{120,30} };
	Solution *p=new Solution();
	double ans=p->fractionKnapsack(n,weight,arr);
	cout<<setprecision(3)<<fixed<<ans<<nl;	
    return 0;
}