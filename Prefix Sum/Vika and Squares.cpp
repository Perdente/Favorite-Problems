//https://codeforces.com/contest/610/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
const int oo=1e12;

void Malena(){
	int n;cin>>n;
	vector<int> v(n);
	int mi=oo;
	for(auto &i:v){
		cin>>i;
		mi=min(mi,i);
	}
	vector<int> u(n);
	for(int i=0;i<n;++i){
		if(v[i]!=mi){
			u[i]=1;
		}
		else u[i]=0;
	}
	int sum=0,ma=0;
	for(int i=0;i<2*n;++i){
		if(u[i%n]==0){
			ma=max(ma,sum);
			sum=0;
		}else{
			sum++;
		}
	}
	cout<< mi*n + max(ma,sum)<<endl;

}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	t=1;
	//cin>>t;
	while(t--) Malena();
	return 0;
}
