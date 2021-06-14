//https://atcoder.jp/contests/abc205/tasks/abc205_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,q;cin>>n>>q;
	vector<int>v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	while(q--){
		int k;cin>>k;
		int l=0,r=2e18;
		while(r>l+1){
			int m=(l+r)/2;
			if(m-(upper_bound(v.begin(),v.end(),m)-v.begin())>=k)r=m;
			else l=m;
		}
		cout<<r<<endl;
	}

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
	//cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
