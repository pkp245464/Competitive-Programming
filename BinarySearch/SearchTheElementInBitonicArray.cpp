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
    int findPeakElement(vector<int>&nums) {
        int n = nums.size();
        if(n==1) return 0;
        int l = 0;
        int h = n - 1;
        while(l <= h) {
            int mid = l + (h - l)/2;
            if(mid > 0 && mid < n -1) {
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                    return mid;
                }
                else if(nums[mid-1] > nums[mid] && nums[mid+1]) {
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if(mid == 0) {
                if(nums[0] > nums[1]) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
            else if(mid == n-1){
                if(nums[n-1] > nums[n-2]) {
                    return n-1;
                }
                else {
                    return n-2;
                }
            }
        }
        return -1;
    }
    int binarySearchAsc(int l,int h,vector<int>&nums,int target) {
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(target > nums[mid]) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return -1;
    }
    int binarySearchDesc(int l,int h,vector<int>&nums,int target) {
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(target > nums[mid]) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
    int bitonicArray(vector<int>&nums,int target) {
        int a = findPeakElement(nums);
        int first=binarySearchAsc(0,a-1,nums,target);
        int second=binarySearchDesc(a-1,nums.size()-1,nums,target);
        return max(first,second);
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution *p=new Solution();
    vector<int>arr{1,3,8,12,4,2};
    int target=2;
    cout<<p->bitonicArray(arr,target);;
    return 0;
}