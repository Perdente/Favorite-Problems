//https://codeforces.com/problemset/problem/1510/K
#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;cin>>n;
	vector<int>v(n*2);
	for(int i=0;i<n*2;++i)cin>>v[i];
	vector<int>u(v);
	sort(u.begin(),u.end());
	
	if(u==v)return cout<<0<<'\n',0;
	
	tuple<vector<int>,vector<int>,int>my_tuple;
	my_tuple=make_tuple(v,v,0);
	int cnt=0;
	while(true){
		cnt++;
		vector<int>first=get<0>(my_tuple),second=get<1>(my_tuple);
		if(get<2>(my_tuple)==0){
			for(int i=0;i<n;++i)
				swap(first[i],first[n+i]);
			for(int i=0;i<2*n;i+=2)
				swap(second[i],second[i+1]);
		}
		else{
			for(int i=0;i<n;++i)
				swap(second[i],second[n+i]);
			for(int i=0;i<2*n;i+=2)
				swap(first[i],first[i+1]);
		}
		if(first==u or second==u)return cout<<cnt<<'\n',0;
		if(first==v or second==v)return cout<<-1<<'\n',0;
		int temp=1-get<2>(my_tuple);
		my_tuple=make_tuple(first,second,temp);
	}
	return 0;
}
