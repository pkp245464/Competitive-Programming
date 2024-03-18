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
    void josephusProblem(int ind,int k,vector<int>&nums,int &ans) {
        if(nums.size() == 1) {
            ans = nums[0]; 
            return;
        }
        ind = ((ind + k) % nums.size());
        nums.erase(nums.begin()+ind);
        josephusProblem(ind,k,nums,ans);
    }
    int findTheWinner(int n, int k) {
        vector<int>nums;
        int ans = -1;  
        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        k = k - 1;
        josephusProblem(0,k,nums,ans);
        return ans;
    }
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution *p = new Solution();
    int n = 40;
    int k = 7;
    cout<<p->findTheWinner(n,k);
    return 0;

}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Second Method

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
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
          ans = (ans + k) % i;
        return ans + 1;
    }
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution *p = new Solution();
    int n = 40;
    int k = 7;
    cout<<p->findTheWinner(n,k);
    return 0;

}
*/
