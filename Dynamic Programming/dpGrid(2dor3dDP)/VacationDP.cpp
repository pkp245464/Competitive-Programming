//Recursion Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long  
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int lastDay,vector<vector<int>>&arr) {
    if(ind == 0) {
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if(i != lastDay) {
                maxi = max(maxi,arr[ind][i]);
            }
        }
        return maxi;
    }
    int maxi = INT_MIN;
    for(int i = 0; i < 3; i++) {
        if(i != lastDay) {
            int activity = arr[ind][i]  + fun(ind - 1,i,arr);
            maxi = max(maxi,activity);
        }
    }
    return maxi;
}
int maximumHappiness(vector<vector<int>>&arr) {
    int n = arr.size();
    return fun(n - 1,3,arr);
}
int main(){
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    cout << maximumHappiness(arr) << nl;
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Memoization Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int fun(int ind,int lastDay,vector<vector<int>>&arr,vector<vector<int>>&dp) {
    if(ind == 0) {
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if(i != lastDay) {
                maxi = max(maxi,arr[ind][i]);
            }
        }
        return dp[ind][lastDay] = maxi;
    }
    if(dp[ind][lastDay] != -1) {
        return dp[ind][lastDay];
    }
    int maxi = INT_MIN;
    for(int i = 0; i < 3; i++) {
        if(i != lastDay) {
            int activity = arr[ind][i]  + fun(ind - 1,i,arr,dp);
            maxi = max(maxi,activity);
        }
    }
    return dp[ind][lastDay] = maxi;
}
int maximumHappiness(vector<vector<int>>&arr) {
    int n = arr.size();
    vector<vector<int>>dp(n + 1,vector<int>(4,-1));
    return fun(n - 1,3,arr,dp);
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    cout << maximumHappiness(arr) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Tabulation Method

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int maximumHappiness(vector<vector<int>>&arr) {
    int n = arr.size();
    vector<vector<int>>dp(n + 1,vector<int>(4,0));
    dp[0][0] = max(arr[0][1],arr[0][2]);
    dp[0][1] = max(arr[0][0],arr[0][2]);
    dp[0][2] = max(arr[0][0],arr[0][1]);
    dp[0][3] = max(arr[0][0],max(arr[0][1],arr[0][2]));

    for(int day = 1; day < n; day++) {
        for(int lastDay = 0; lastDay < 4; lastDay++) {
            dp[day][lastDay] = 0;
            for(int task = 0; task < 3; task++) {
                if(task != lastDay) {
                    int activity = arr[day][task]  + dp[day - 1][task];
                    dp[day][lastDay] = max(dp[day][lastDay],activity);
                }
            }
        }
    }
    return dp[n - 1][3];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    cout << maximumHappiness(arr) << nl;
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/


/*
//Space Optimization

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int maximumHappiness(vector<vector<int>>&arr) {
    int n = arr.size();
    vector<int>prev(4,0);
    prev[0] = max(arr[0][1],arr[0][2]);
    prev[1] = max(arr[0][0],arr[0][2]);
    prev[2] = max(arr[0][0],arr[0][1]);
    prev[3] = max(arr[0][0],max(arr[0][1],arr[0][2]));

    for(int day = 1; day < n; day++) {
        vector<int>temp(4,0);
        for(int lastDay = 0; lastDay < 4; lastDay++) {
            temp[lastDay] = 0;
            for(int task = 0; task < 3; task++) {
                if(task != lastDay) {
                    temp[lastDay] = max(temp[lastDay],arr[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    cout << maximumHappiness(arr) << nl;
    return 0;
}
*/