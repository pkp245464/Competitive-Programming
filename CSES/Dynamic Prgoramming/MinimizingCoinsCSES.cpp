#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1,0));
        
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            }
            else {
                dp[0][i] = 1e9;
            }
        }
        for(int ind = 1; ind < n; ind++) {
            for(int target = 0; target <= amount; target++) {
                int notTaken = 0 + dp[ind - 1][target];
                int taken = 1e9;
                if(coins[ind] <= target) {
                    taken = 1 + dp[ind][target - coins[ind]];
                }
                dp[ind][target] = min(taken,notTaken);
            }
        }
        int ans = dp[n - 1][amount];
        if(ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};
int main(){
    fastinput;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p = new Solution();
    int n,target;
    cin >> n >> target;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << p->coinChange(arr,target) << nl;    
    return 0;
}