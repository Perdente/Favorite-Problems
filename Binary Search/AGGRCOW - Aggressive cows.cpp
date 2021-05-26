//https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e9;
void Malena(){
	int n,c;cin>>n>>c;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	sort(v.begin(), v.end());
	auto good=[&](int m)->bool{
		int j=0,cnt=0;
		for(int i=1;i<n;++i){
			if(v[i]-v[j]>=m)cnt++,j=i;
		}
		return cnt>=(c-1);
	};
	int l=1,r=N;
	while(r>l+1){
		int m=(l+r)>>1;
		if(good(m)){
			l=m;
		}else{
			r=m;
		}
	}
	cout<<l<<'\n';
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
