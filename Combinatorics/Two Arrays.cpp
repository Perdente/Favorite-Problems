//https://codeforces.com/contest/1288/problem/C
//https://codeforces.com/blog/entry/73105#comment-573588
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long
#define mx 1000005
int fact[mx];
int binpow(int a,int b)
{
	int res=1;
	while(b>0)
	{
		if(b%2)res=(res*1ll*a)%mod;
		a=(a*1ll*a)%mod;
		b>>=1;
	}
	return res;
}
int ncr(int n,int k)
{
	if(k>n)return 0;
	int res=fact[n];
	res=(res*1ll*binpow(fact[k],mod-2))%mod;
	res=(res*1ll*binpow(fact[n-k],mod-2))%mod;
	return res;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0]=fact[1]=1;
    for(int i=2;i<=mx;++i)
    {
    	fact[i]=(fact[i-1]*1ll*i)%mod;
	}
	int n,m;cin>>n>>m;
	cout<<ncr(n+2*m-1,n-1)<<endl;	
	return 0;
}
