//https://www.spoj.com/problems/MAIN8_C/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
const int N = 1e18+5;

void Malena(){
	int n,k;cin>>n>>k;
	vector<int> v(n);
	for(auto &it:v){
		cin>>it;
	}
	auto good=[&](int m){
		int cnt=0;
		for(auto it:v){
			cnt+=(it/m);
		}
		return (cnt>=k);
	};
	int l=0,r=N;
	while(r>l+1){
		int m=l+(r-l+1)/2;
		if(good(m)){
			l=m;
		}else{
			r=m;
		}
	}
	cout<<l<<endl;
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
