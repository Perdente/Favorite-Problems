//https://www.spoj.com/problems/PRATA/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e9;
void Malena(){
	int n,c;cin>>c>>n;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	sort(v.begin(), v.end());
	auto good=[&](int m)->bool{
		int cnt=0;
		for(int i=0;i<n;++i){
			int sum=0,j=1;
			while(sum+v[i]*j<=m)sum+=v[i]*j,cnt++,j++;
		}
		return cnt>=c;
	};
	int l=0,r=N;
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
