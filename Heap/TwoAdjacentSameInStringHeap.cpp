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
#define nle "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------------------------------------------------------///
const int MAX_CHAR=26;
class Key {
public:
	int freq;
	char ch;
	bool operator<(const Key &k) const {
		return freq<k.freq;
	}
};
void rearrangeString(string str) {
	int n=str.length();
	int count[MAX_CHAR]={0};
	for(int i=0;i<n;i++)
		count[str[i]-'a']++;
	
	priority_queue<Key>pq;
	for(char c='a';c<='z';c++) {
		int val=c-'a';
		if(count[val]) {
			pq.push(Key{count[val],c});
		}
	}
	str="";
	Key prev{-1,'#'};
	while(!pq.empty()) {
		Key k=pq.top();
		pq.pop();
		str+=k.ch;
		if(prev.freq>0)
			pq.push(prev);
		(k.freq)--;
		prev=k;
	}
	if(n!=str.length())
		cout<<"Not Valid String"<<nle;
	else
		cout<<str<<nle;
}
int main(){
	fastinput;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string str="bbbaa";
	rearrangeString(str);
	return 0;
}

