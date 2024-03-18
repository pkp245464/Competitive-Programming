#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define phb push_back
#define phf push_front
#define ppf pop_front
#define ppb pop_back
#define in insert
#define as assign
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
int minIndex(queue<int>&q,int sortedindex) {
	int min_index=-1;
	int min_val=INT_MAX;
	int n=q.size();
	for(int i=0;i<n;i++) {
		int curr=q.front(); q.pop();
		if(curr<=min_val && i<=sortedindex) {
			min_index=i;
			min_val=curr;
		}
		q.push(curr);
	}
	return min_index;
}
void insertMinToRear(queue<int>&q,int min_index) {
	int min_val;
	int n=q.size();
	for(int i=0;i<n;i++) {
		int curr=q.front(); q.pop();
		if(i!=min_index)
			q.push(curr);
		else
			min_val=curr;
	}
	q.push(min_val);
}
void sortQueue(queue<int>&q) {
	for(int i=1;i<=q.size();i++) {
		int min_index=minIndex(q,q.size()-i);
		insertMinToRear(q,min_index);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	queue<int>q;
	q.push(30);
	q.push(11);
	q.push(15);
	q.push(4);
	q.push(81);
	sortQueue(q);
	while(q.empty()==false) {
		cout<<q.front()<<" "; q.pop();
	}
	cout<<"\n";
    return 0;
}