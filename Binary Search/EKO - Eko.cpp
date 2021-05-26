//https://www.spoj.com/problems/EKO/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e9;
void Malena(){
	int n,c;cin>>n>>c;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	sort(v.begin(), v.end());
	auto good=[&](int m)->bool{
		int sum=0;
		for(int i=0;i<n;++i){
			sum+=max(0LL,v[i]-m);
		}
		return sum>=c;
	};
	int l=0,r=N;
	while(r>l+1){
		int m=l+(r-l)/2;
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
	//cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
