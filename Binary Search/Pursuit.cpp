//https://codeforces.com/contest/1530/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n;cin>>n;
	vector<int>v(n),u(n);
	for(int i=0;i<n;++i)cin>>v[i];
	for(int i=0;i<n;++i)cin>>u[i];
	auto good=[&](int m)->bool{
		vector<int>vv,uu;
		vv=v,uu=u;
		for(int i=0;i<m;++i){
			vv.push_back(100);
			uu.push_back(0);
		}
		sort(vv.begin(), vv.end(),greater<int>());
		sort(uu.begin(), uu.end(),greater<int>());
		int p=(int)vv.size()/4;
		for(int i=0;i<p;++i){
			vv.pop_back();uu.pop_back();
		}
		return accumulate(vv.begin(), vv.end(),0LL)>=accumulate(uu.begin(), uu.end(),0LL);
	};
	int l=-1,r=n+1;
	while(r>l+1){
		int m=l+(r-l)/2;
		if(good(m)){
			r=m;
		}else{
			l=m;
		}
	}
	cout<<r<<'\n';
}

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
