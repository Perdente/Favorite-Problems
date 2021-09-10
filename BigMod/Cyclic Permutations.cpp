//https://codeforces.com/contest/1391/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;

ll bigmod(ll a,ll b,ll m)
{
	  if(!b)  return 1%m;
    ll temp=bigmod(a,b/2,m);
    if(b%2ll)
    {
        return (((temp*temp)%m)*a)%m;
    }
    return (temp*temp)%m;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;cin>>n;
    ll fact=1;
    for(ll i=1;i<=n;++i)
    {
        fact*=i;
        fact%=mod;
    }
    ll ans=fact-bigmod(2,n-1,mod);
    if(ans<0)
    {
        ans+=mod;
    }
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}
