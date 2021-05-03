//https://ibb.co/BV14L2F
//https://atcoder.jp/contests/zone2021/tasks/zone2021_b
#include<bits/stdc++.h>
using namespace std;
#define int long double

void Malena(){
	int n,D,H;cin>>n>>D>>H;
	vector<vector<int>>bars(n,vector<int>(2));
	for(int i=0;i<n;++i){
		cin>>bars[i][0]>>bars[i][1];
	}
	int ma=0,x;
	for(int i=0;i<n;++i){
		x=(bars[i][1]-(bars[i][0]*(H-bars[i][1]))/(D-bars[i][0]));
		ma=max(ma,x);
	}
	cout<<setprecision(12)<<ma<<'\n';
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
