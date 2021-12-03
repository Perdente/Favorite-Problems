//https://www.codechef.com/problems/MINEAT
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
const int N=1e9+5;
int ceil(int A,int B)   {if(A%B==0)return A/B;else return (A/B)+1LL;}
void Malena(){
	int n,k;cin>>n>>k;
	vector<int> v(n);
	for(auto &it:v){
		cin>>it;
	}
	//sort(v.begin(), v.end());
	auto good=[&](int m){
		int cnt=0;
		for(auto it:v){
			cnt+=ceil(it,m);
		}
		return cnt<=k;
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
	cout<<r<<endl;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t,tc=0;
	t=1;
	cin>>t;
	while(t--) {
		Malena();
	}
	return 0;
}
