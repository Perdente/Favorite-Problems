//https://www.spoj.com/problems/LITE/
//Lazy propagation
#include<bits/stdc++.h>
using namespace std;
#define mx 1000005

int seg[4*mx];
int lazy[4*mx];

int query(int seg_si,int seg_str,int seg_end,int q_str,int q_end)
{
	if(lazy[seg_si]!=0)
	{
		lazy[seg_si]%=2;
		if(lazy[seg_si]==1)
		{
			seg[seg_si] = (seg_end-seg_str+1)-seg[seg_si];
			if(seg_str!=seg_end)
			{
				lazy[2*seg_si+1]++;
				lazy[2*seg_si+2]++;
				lazy[2*seg_si+1]%=2;
				lazy[2*seg_si+2]%=2;
			}
			lazy[seg_si]=0;
		}
	}
	if(seg_str>seg_end or seg_str>q_end or seg_end<q_str)return 0;
	if(seg_str>=q_str and seg_end<=q_end)return seg[seg_si];
	int mid=(seg_str+seg_end)/2;
	int x=query(2*seg_si+1,seg_str,mid,q_str,q_end);
	int y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	return x+y;
}

void update(int seg_si,int seg_str,int seg_end,int q_str,int q_end)
{
	if(lazy[seg_si]!=0)//if lazy contains previous value
	{
		lazy[seg_si]%=2;
		if(lazy[seg_si]==1)
		{
			seg[seg_si] = (seg_end-seg_str+1)-seg[seg_si];
			if(seg_str!=seg_end)
			{
				lazy[2*seg_si+1]++;
				lazy[2*seg_si+2]++;
				lazy[2*seg_si+1]%=2;
				lazy[2*seg_si+2]%=2;
			}
			lazy[seg_si]=0;
		}
	}
	if(seg_str>seg_end or seg_str>q_end or seg_end<q_str) return ;//no overlap
	if(seg_str>=q_str and seg_end<=q_end)//total overlap
	{
		seg[seg_si]=(seg_end-seg_str+1)-seg[seg_si];//update the range
		if(seg_str!=seg_end)//if not leaf not then update its children
		{
			lazy[2*seg_si+1]++;
			lazy[2*seg_si+2]++;
			lazy[2*seg_si+1]%=2;
			lazy[2*seg_si+2]%=2;
		}
		return ;
	}
	int mid=(seg_str+seg_end)/2;
	
	update(2*seg_si+1,seg_str,mid,q_str,q_end);
	update(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	
	seg[seg_si]=seg[2*seg_si+1]+seg[2*seg_si+2];
}

int main()
{
	int n,q;
	cin>>n>>q;
	while(q--)
	{
		int x,l,r;
		cin>>x>>l>>r;
		l--,r--;
		if(x)
		{
			cout<<query(0,0,n-1,l,r)<<endl;
		}
		else
		{
			update(0,0,n-1,l,r);
		}
	}
	
	return 0;
}
