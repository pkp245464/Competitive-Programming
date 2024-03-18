#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------//
int search(vector<int>& nums, int target) {
	int l = 0;
	int h = nums.size() - 1;
	while(l <= h) {
		int mid = l + (h - l) / 2;
		if(nums[mid] == target) {
			return mid;
		}
		else if(nums[mid] > target) {
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}
int main() {
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int>arr = {-1,0,3,5,9,12};
	int target = 9;
	cout << search(arr,target) << nl;
    return 0;
}

//in better way
#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n,q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int l = -1; 
        int r = n; 
        while(l + 1 < r) {
            int m = l + (r - l) / 2;
            if(a[m] < x) {
                l = m;
            }
            else {
                r = m;
            }
        }
        if(r < n && a[r] == x) {
            cout << "YES" << " " << r << nl;
        }
        else {
            cout << "NO" << nl;
        }
    }
    return 0;
}
/*
I/P:
10 6
9 13 16 27 30 33 34 39 44 81
3 9 82 81 30 28
O/P:
NO
YES 0
NO
YES 9
YES 4
NO
*/

/*
//Nearly Sorted Array ex- arr = {5,10,30,20,40}
#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define llu unsigned long long int
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
int nearlySortedArray(vector<int>&nums,int target) {
    int l = 0,h = nums.size()-1;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(mid - 1 >= l && nums[mid - 1] == target) {
            return mid - 1;
        }
        if(mid + 1 <= h && nums[mid + 1] == target) {
            return mid + 1;
        }
        else if(target > nums[mid]) {
            l = mid + 2;
        }
        else {
            h = mid - 2;
        }
    }
    return -1;
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    vector<int>arr{5,10,30,20,40};
    int target = 10;
    cout << nearlySortedArray(arr,target) << nl;
    return 0;
}
*/