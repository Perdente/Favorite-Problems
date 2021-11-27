//https://codeforces.com/problemset/problem/1506/D
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void Malena(){
	int n;cin>>n;
	vector<int> v(n);
	map<int,int> mp;
	int ma=0;
	for(int i=0;i<n;++i){
		cin>>v[i];
		mp[v[i]]++;
	}
	priority_queue<int> pq;
	for(auto [key,value]:mp){
		pq.push(value);
	}
	int temp=0;
	while(pq.size()>1){
		int t=pq.top();
		pq.pop();
		int u=pq.top();
		pq.pop();
		if(t-1>0)pq.push(t-1);
		if(u-1>0)pq.push(u-1);
	}
	cout<<(pq.size()?pq.top():0)<<endl;

}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--) Malena();
	return 0;
}
