//https://atcoder.jp/contests/abc179/tasks/abc179_d
//Lazy propagation

#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define ll long long
#define mod 998244353

ll seg[4*mx];
ll lazy[4*mx];

ll n,k;
void add(ll & a,ll b)
{
	a%=mod;b%=mod;a+=b;a%=mod;
}

ll query(ll seg_si,ll seg_str,ll seg_end,ll ind)
{
	if(seg_str>n-1 or seg_str<0 or seg_end>n-1 or seg_end<0) return 0;
	
	add(seg[seg_si],lazy[seg_si]);
	
	if(seg_str!=seg_end)
	{
		add(lazy[2*seg_si+1],lazy[seg_si]);
		add(lazy[2*seg_si+2],lazy[seg_si]);
	}
	lazy[seg_si]=0;
	
	
	if(seg_str>ind or seg_end<ind or seg_str>seg_end)return 0;
	if(seg_str==seg_end and seg_str==ind)return seg[seg_si];
	
	ll sum=0;
	ll mid=(seg_str+seg_end)/2;
	ll x=query(2*seg_si+1,seg_str,mid,ind);
	ll y=query(2*seg_si+2,mid+1,seg_end,ind);
	add(sum,x);
	add(sum,y);
	return sum;
}

void update(ll seg_si,ll seg_str,ll seg_end,ll q_str,ll q_end,ll value)
{
	if(seg_str>n-1 or seg_str<0 or seg_end>n-1 or seg_end<0) return ;

	add(seg[seg_si],lazy[seg_si]);
	if(seg_str!=seg_end)
	{
		add(lazy[2*seg_si+1],lazy[seg_si]);
		add(lazy[2*seg_si+2],lazy[seg_si]);
	}
	lazy[seg_si]=0;

	if(seg_str>seg_end or seg_str>q_end or seg_end<q_str) return ;
	if(seg_str>=q_str and seg_end<=q_end)
	{
		add(lazy[seg_si],value);
		return ;
	}
	ll mid=(seg_str+seg_end)/2;
	
	update(2*seg_si+1,seg_str,mid,q_str,q_end,value);
	update(2*seg_si+2,mid+1,seg_end,q_str,q_end,value);
	
}

int main()
{
	cin>>n>>k;
	pair<ll,ll>dm[k];
	for(ll i=0;i<k;++i)
	{
		ll a,b;cin>>a>>b;
		dm[i]={a,b};
	}
	
	update(0,0,n-1,0,0,1);
	for(ll i=1;i<n;++i)
	{
		for(ll j=0;j<k;++j)
		{
			ll x=dm[j].first;
			ll y=dm[j].second;
			ll z=query(0,0,n-1,i-1);
			update(0,0,n-1,i+x-1,i+y-1,z);
		}
	}
	ll ans=query(0,0,n-1,n-1);
	cout<<ans<<endl;	
	return 0;
}
