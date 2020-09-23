//Lazy Propagation
//https://www.spoj.com/problems/HORRIBLE/
#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
typedef long long ll;
ll seg[4*mx];
ll lazy[4*mx];

void bld_segtree(int seg_si,int seg_str,int seg_end)
{
	if(seg_str>seg_end)return;
	if(seg_str==seg_end)
	{
		seg[seg_si]=0;return;
	}
	int mid=(seg_str + seg_end)/2;
	bld_segtree(2*seg_si+1,seg_str,mid);//recurse on the left child
	bld_segtree(2*seg_si+2,mid+1,seg_end);//recurse on the right child
	seg[seg_si]=seg[2*seg_si+1]+seg[2*seg_si+2];
}

ll query(int seg_si,int seg_str,int seg_end,ll q_str,ll q_end)
{
	if(lazy[seg_si]!=0)
	{
		seg[seg_si]+=(seg_end-seg_str+1)*lazy[seg_si];
		if(seg_str!=seg_end)
		{
			lazy[2*seg_si+1]+=lazy[seg_si];
			lazy[2*seg_si+2]+=lazy[seg_si];
		}
		lazy[seg_si]=0;
	}
	if(seg_str>q_end or seg_end<q_str)return 0;
	if(seg_str>=q_str and seg_end<=q_end)return seg[seg_si];
	int mid=(seg_str+seg_end)/2;
	ll x=query(2*seg_si+1,seg_str,mid,q_str,q_end);
	ll y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	return x+y;
}

void update(int seg_si,int seg_str,int seg_end,ll q_str,ll q_end,ll value)
{
	if(lazy[seg_si]!=0)//if lazy contains previous value
	{
		seg[seg_si]+=(seg_end-seg_str+1)*lazy[seg_si];
		if(seg_str!=seg_end)
		{
			lazy[2*seg_si+1]+=lazy[seg_si];
			lazy[2*seg_si+2]+=lazy[seg_si];
		}
		lazy[seg_si]=0;
	}
	if(seg_str>q_end or seg_end<q_str) return ;//no overlap
	if(seg_str>=q_str and seg_end<=q_end)//total overlap
	{
		seg[seg_si]+=(seg_end-seg_str+1)*value;//update the range
		if(seg_str!=seg_end)//if not leaf not then update its children
		{
			lazy[2*seg_si+1]+=value;
			lazy[2*seg_si+2]+=value;
		}
		return ;
	}
	int mid=(seg_str+seg_end)/2;
	
	update(2*seg_si+1,seg_str,mid,q_str,q_end,value);
	update(2*seg_si+2,mid+1,seg_end,q_str,q_end,value);
	
	seg[seg_si]=seg[2*seg_si+1]+seg[2*seg_si+2];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		memset(lazy,0,sizeof(lazy));
		memset(seg,0,sizeof(seg));
		bld_segtree(0,0,n-1);
		while(q--)
		{
			ll c,l,r,v;
			cin>>c;
			if(c)
			{
				cin>>l>>r;
				l--,r--;
				cout<<query(0,0,n-1,l,r)<<endl;
			}
			else
			{
				cin>>l>>r>>v;
				l--,r--;
				update(0,0,n-1,l,r,v);
			}
		}
	}	
	return 0;
}
