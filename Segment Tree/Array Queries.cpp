/*http://www.lightoj.com/volume_showproblem.php?problem=1082*/

#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define mx 100006
int num[mx];
int seg[4*mx];


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
	if(seg_str>q_end or seg_end<q_str)return INT_MAX;
	if(seg_str>=q_str and seg_end<=q_end)return seg[seg_si];
	int mid=(seg_str+seg_end)/2;
	int x=query(2*seg_si+1,seg_str,mid,q_str,q_end);
	int y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	return min(x,y);
}

int main()
{
	int t;scanf("%d",&t);
	for(int test=1;test<=t;++test)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&num[i]);
		}
		bld_segtree(0,0,n-1);
		printf("Case %d:\n",test);
		while(q--)
		{
			int l,r;scanf("%d%d",&l,&r);
			printf("%d\n",query(0,0,n-1,l-1,r-1));
		}
	}
	
}
