//Combination sum But repeated is not allowed

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
    void totalComination(int ind,int target,vector<int>&ds,vector<int>&arr) {
        if(target == 0) {
            for(auto it : ds) {
                cout<<it<<" ";
            } 
            cout<<nl;
            return;
        }
        for(int i = ind;i < arr.size(); i++) {
            if(i > ind && arr[i] == arr[i - 1]) {
                continue;
            } 
            if(arr[i] > target) {
                break;
            } 
            ds.push_back(arr[i]);
            totalComination(i + 1,target - arr[i],ds,arr);
            ds.pop_back();
        }
    }
};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p = new Solution();
    vector<int>ds,arr{10,1,2,7,6,1,5};
    sort(arr.begin(),arr.end());
    int target = 8;
    p->totalComination(0,target,ds,arr);
    return 0;
}
/*
O/p:
1 1 6 
1 2 5 
1 7 
2 6 
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*
//Combination Sum But element is repeated 

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
    void totalCombination(int ind,int target,vector<int>&ds,vector<int>&arr) {
        if(ind == arr.size()) {
            if(target == 0) {
                for(auto it : ds) {
                    cout<<it<<" ";
                }
                cout<<nl;
            }
            return;
        }
        if(arr[ind] <= target) {
            ds.push_back(arr[ind]);
            totalCombination(ind,target - arr[ind],ds,arr);
            ds.pop_back();
        }
        totalCombination(ind + 1,target,ds,arr);
    }
};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution *p = new Solution();
    int target = 7;
    vector<int>ds,arr{2,3,6,7};
    p->totalCombination(0,target,ds,arr);
    return 0;
}
o/p:
2 2 3 
7 
*/

