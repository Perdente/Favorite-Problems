//https://www.spoj.com/problems/RMQSQ/
#include<bits/stdc++.h>
using namespace std;
#define mx 10005
int num[mx];
int seg[4*mx];
int lazy[4*mx];
void bld_segtree(int seg_si,int seg_str,int seg_end)
{
	if(seg_str==seg_end)
	{
		seg[seg_si]=num[seg_str];return ;
	}
	int mid=(seg_str + seg_end)/2;
	bld_segtree(2*seg_si+1,seg_str,mid);//recurse on the left child
	bld_segtree(2*seg_si+2,mid+1,seg_end);//recurse on the right child
	seg[seg_si]=min(seg[2*seg_si+1],seg[2*seg_si+2]);
}
int query(int seg_si,int seg_str,int seg_end,int q_str,int q_end)
{
	if(lazy[seg_si]!=0)
	{
		seg[seg_si]+=lazy[seg_si];
		if(seg_str!=seg_end)
		{
			lazy[2*seg_si+1]+=lazy[seg_si];
			lazy[2*seg_si+2]+=lazy[seg_si];
		}
		lazy[seg_si]=0;
	}
	if(seg_str>q_end or seg_end<q_str)return INT_MAX;
	if(seg_str>=q_str and seg_end<=q_end)return seg[seg_si];
	int mid=(seg_str+seg_end)/2;
	int x=query(2*seg_si+1,seg_str,mid,q_str,q_end);
	int y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	return min(x,y);
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>num[i];
	}
	memset(lazy,0,sizeof(lazy));
	bld_segtree(0,0,n-1);//from root = 0 we construct from index 0 to index 3 segment tree in arr_min[]
//	for(int i=0;i<4*n;++i)
//	{
//		cout<<seg[i]<<" ";
//	}
//	cout<<endl;
	int q;cin>>q;
	while(q--)
	{
		int l,r;cin>>l>>r;
		cout<<query(0,0,n-1,l,r)<<endl;
	}

	
}
