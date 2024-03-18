//length of Longest Subarray with given Sum K(handle both positve and negative number)
//TC: O(n * n)
int getLongestSubarray(vector<int>&a,ll k) {
    int n = a.size(),len = 0;
    for(int i = 0; i < n; i++) {
        ll curSum = 0; 
        for(int j = i; j < n; j++) { 
            curSum += a[j];
            if(curSum == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
//length of Longest Subarray with given Sum K(handle both positve and negative number)
//TC: O(n)
int getLongestSubarray(vector<int>&a,ll k) {
    ll sum = 0;
    int n = a.size(),len = 0;
    map<ll,int>m;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == k) {
            len = max(len, i + 1);
        }
        ll rem = sum - k;
        if(m.find(rem) != m.end()) {
            int len = i - m[rem];
            len = max(len, len);
        }
        if(m.find(sum) == m.end()) {
            m[sum] = i;
        }
    }
    return len;
}
//count subarrays with given k sum (Handle only positive number)
//https://cses.fi/problemset/task/1660
//TC: O(n) 
int cntSubarrayKSum(vector<int>&a,int k) {
    int i = 0,j = 0,cnt = 0,n = (int)a.size();
    ll sum = 0;
    while(j < n) {
        sum += a[j];
        while(sum >= k) {
            if(sum == k) {
                cnt++;
            }
            sum -= a[i];
            i++;
        }
        j++;
    }
    return cnt;
}
//count subarrays with given k sum(handle both pos & neg number)
//https://cses.fi/problemset/task/1661
//TC: O(n) 
ll cntSubarrayKSum(vector<int>&a,int k) {
    ll sum = 0,cnt = 0;
    map<ll,int>m;
    m[0]++;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i];
        cnt += m[sum - k];
        m[sum]++;
    }
    return cnt;
}
//count the number of subarrays where the sum of values is divisible by n
//https://cses.fi/problemset/task/1662
//TC: O(n)
ll cntSubarrayKSum(vector<int>&a) {
    int n = (int)a.size();
    ll sum = 0,cnt = 0;
    map<ll,int>m;
    m[0]++;
    for(int i = 0; i < n; i++) {
        sum += (a[i] % n);
        sum = (sum + n) % n; // handle pos & neg number with modulo
        cnt += m[sum];
        m[sum]++;
    }
    return cnt;
}
//the number of subarrays that have at most k distinct values
ll cntSubarrayDistinct(vector<int>&a,int k) {
    ll cnt = 0;
    map<int,int>m;
    for(int i = 0,j = 0; i < (int)a.size(); i++) {
        while(j < (int)a.size() && ((int)m.size() < k || m.count(a[j]) > 0)) {
            m[a[j]]++;
            j++;
        }
        cnt += j - i;
        m[a[i]]--;
        if(m[a[i]] == 0) {
            m.erase(a[i]);
        }
    }
    return cnt;
}
//Length of the longest subarray with zero Sum (handle both pos & neg number)
//TC: O(n)
int LongestSubarrayWithZeroSum(vector<int>&a) {
    int mx = 0,n = (int)a.size();
    ll sum = 0;
    map<ll,int>m;
    for(int i = 0; i< n; i++) {
        sum += a[i];
        if(sum == 0) {
            mx = i + 1;
        }
        else {
            if(m.find(sum) != m.end()) {
                mx = max(mx,i - m[sum]);
            }
            else {
                m[sum] = i;
            }
        }
    }
    return mx;
}
/*find the subarray such that sum of all odd and even index value is equal
a[] = {1,2,11,4,1,5,1,2}
l = 2,r = 8; [from l to r subarray with equal sum of odd and even index]
odd index value = 11,1,1 = 13
even index value = 2,4,5,2 = 13
//https://codeforces.com/contest/1915/problem/E
Sol- we can do with "Length of the longest subarray with zero Sum (handle both pos & neg number)" need
little changes we just multiply array '-' with odd index.
*/
bool subarrayWithOddEvenValueEqual(vector<int>&a) {
	int n = (int)a.size();
    for(int i = 0; i < n; i++) {
    	if(i & 1) a[i] *= -1;
    }
    ll sum = 0;
    set<ll>st = {0};
    for(int i = 0; i < n; i++) {
    	sum += a[i];
    	if(st.find(sum) != st.end()) {
    		return true;
    	}
    	st.insert(sum);
    }
    return false;
}

/*
// divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.
https://cses.fi/problemset/task/1085/
I/P: 
n = 5,k = 3
a[] = {2,4,7,3,5}
O/P: 8 {[2,4],[7],[3,5]} //max sum of subarray is 8 which is minimum sum
*/
ll minSumSubarray(ll k,vector<int>&a) {
    ll l = *max_element(a.begin(),a.end());
    ll r = 1e18;
    ll mxSum = 1e18;
    while(l <= r) {
        ll m = l + (r - l) / 2;
        int block = 1;
        ll sum = 0;
        for(int i = 0; i < a.size(); i++) {
            if(sum + a[i] > m) {
                sum = 0;
                block++;
            }
            sum += a[i];
        }
        if(block > k) {
            l = m + 1;
        }
        else {
            if(m < mxSum) {
                mxSum = m;
            }
            r = m - 1;
        }
    }
    return mxSum;
}

/*
//find the subarray a such that absolute difference between its first and last element is exactly k 
  and return the maximum sum of a good subarray of array.
//https://leetcode.com/problems/maximum-good-subarray-sum/description/
*/
ll maximumSubarraySum(vector<int>&a,int k) {
	ll cur = 0,ans = LLONG_MIN;
	map<ll,ll>m;
	for(int i = 0; i < a.size(); i++) {
		if(m.find(a[i]) == m.end()) {
			m[a[i]] = LLONG_MAX;
		}
		m[a[i]] = min(m[a[i]],cur);
		cur += a[i];
		if(m.find(a[i] - k) != m.end()) {
			ans = max(ans,cur - m[a[i] - k]);
		}
		if(m.find(a[i] + k) != m.end()) {
			ans = max(ans,cur - m[a[i] + k]);
		}
	}
	return (ans == LLONG_MIN ? 0 : ans);
}