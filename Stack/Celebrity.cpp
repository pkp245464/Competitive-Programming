// Using Graph
// Time Complexity: O(n^2)
// Space Complexity: O(n)
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
	bool knows(int a,int b,vector<vector<bool>>&matrix) {
		return matrix[a][b];
	}
	int celebrity(vector<vector<bool>>&matrix) {
		int n = matrix.size();
		int indDegree[n] = {0};
		int outDegree[n] = {0};
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				int cnt = knows(i,j,matrix);
				outDegree[i] += cnt;
				indDegree[j] += cnt;

			}
		}
		for(int i = 0; i < n; i++) {
			if(indDegree[i] == n - 1 && outDegree[i] == 0) {
				return i;
			}
		}
		return -1;
	}
};
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p = new Solution();
	vector<vector<bool>>arr = { {0,0,1,0},
								{0,0,1,0},
								{0,0,0,0},
								{0,0,1,0} };
	if(p->celebrity(arr) != -1) {
		cout<<"Celebrity Id: "<<p->celebrity(arr)<<nl;
	}
	else {
		cout<<"No Celebrity"<<nl;
	}	
    return 0;
}

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

// Using Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
/*
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
	bool knows(int a,int b,vector<vector<bool>>&matrix) {
		return matrix[a][b];
	}
	int celebrity(vector<vector<bool>>&matrix) {
		int n = matrix.size();
		stack<int>s;
		for(int i = 0; i < n; i++) {
			s.push(i);
		}
		while(s.size() > 1) {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			if(knows(a,b,matrix)) {
				s.push(b);
			}
			else {
				s.push(a);
			}
		}
		int c = s.top();
		bool knowAny = false;
		bool knownToAll = true;
		// Verify whether the celebrity knows any other person.
		for(int i = 0; i < n; i++) {
			if(knows(c,i,matrix)) {
				knowAny = true;
				break;
			}
		}
		// Verify whether the celebrity is known to all the other person.
		for(int i = 0; i < n; i++) {
			if(i != c && !knows(i,c,matrix)) {
				knownToAll = false;
				break;
			}
		}
		if(knowAny || !knownToAll) {
			c = -1;
		}
		return c;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p = new Solution();
	vector<vector<bool>>arr = { {0,0,1,0},
								{0,0,1,0},
								{0,0,0,0},
								{0,0,0,0} };
	if(p->celebrity(arr) != -1) {
		cout<<"Celebrity Id: "<<p->celebrity(arr)<<nl;
	}
	else {
		cout<<"No Celebrity"<<nl;
	}	
    return 0;
}
*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

// Using Two Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
/*
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
	bool knows(int a,int b,vector<vector<bool>>&matrix) {
		return matrix[a][b];
	}
	int celebrity(vector<vector<bool>>&matrix) {
		int n = matrix.size();
		int i = 0, j = n - 1;
		while(i < j) {
			if(knows(i,j,matrix)) {
				i++;
			}
			else {
				j--;
			}
		}
		int c = i;
		bool knowAny = false;
		bool knownToAll = true;
		// Verify whether the celebrity knows any other person.
		for(int i = 0; i < n; i++) {
			if(knows(c,i,matrix)) {
				knowAny = true;
				break;
			}
		}
		// Verify whether the celebrity is known to all the other person.
		for(int i = 0; i < n; i++) {
			if(i != c && !knows(i,c,matrix)) {
				knownToAll = false;
				break;
			}
		}
		if(knowAny || !knownToAll) {
			c = -1;
		}
		return c;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Solution *p = new Solution();
	vector<vector<bool>>arr = { {0,0,1,0},
								{0,0,1,0},
								{0,0,0,0},
								{0,0,1,0} };
	if(p->celebrity(arr) != -1) {
		cout<<"Celebrity Id: "<<p->celebrity(arr)<<nl;
	}
	else {
		cout<<"No Celebrity"<<nl;
	}	
    return 0;
}
*/