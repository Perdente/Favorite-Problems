//https://codeforces.com/contest/1538/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
  int n,l,r;
  cin>>n>>l>>r;
  vector<int> v(n);
  for(int i=0;i<n;++i){
  	cin>>v[i];
  }
  sort(v.begin(), v.end());
  int sum=0;
  for(int i=0;i<n;++i){
  	int x=upper_bound(v.begin()+i+1,v.end(),r-v[i])-v.begin();
  	int y=lower_bound(v.begin()+i+1,v.end(),l-v[i])-v.begin();
  	if(x<y)continue;
  	sum+=x-y;
  }
  cout<<sum<<'\n';
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
