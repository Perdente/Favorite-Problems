//https://www.geeksforgeeks.org/allocate-minimum-number-pages/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e9;
void Malena(){
	int n,c,tot=0;cin>>n>>c;
	vector<int>v(n);
	for(auto &i:v)cin>>i,tot+=i;
	sort(v.begin(), v.end());
	auto good=[&](int m)->bool{
		int cnt=1,sum=0;
		for(int i=0;i<n;++i){
			if(sum+v[i]<=m)sum+=v[i];
			else{
				cnt++;
				sum=v[i];
			}
		}
		return cnt==c;
	};
	int l=0,r=tot,ans=-1;
	while(r>l+1){
		int m=(l+r)>>1;
		if(good(m)){
			r=m,ans=r;
		}else{
			l=m;
		}
	}
	cout<<ans<<'\n';
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
