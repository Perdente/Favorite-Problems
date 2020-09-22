//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2176
//https://arunima1590.wordpress.com/2017/03/28/uva-11235-frequent-values/
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define mx 100005
int num[mx];
int cnt[mx];
int start[mx];
map<int,int>mp;
int seg[4*mx];

void bld_segtree(int seg_si,int seg_str,int seg_end)
{
	if(seg_str==seg_end)
	{
		seg[seg_si]=cnt[seg_str];return ;
	}
	int mid=(seg_str + seg_end)/2;
	bld_segtree(2*seg_si+1,seg_str,mid);//recurse on the left child
	bld_segtree(2*seg_si+2,mid+1,seg_end);//recurse on the right child
	seg[seg_si]=max(seg[2*seg_si+1],seg[2*seg_si+2]);
}

int query(int seg_si,int seg_str,int seg_end,int q_str,int q_end)
{
	if(seg_str>q_end or seg_end<q_str)return INT_MIN;
	if(seg_str>=q_str and seg_end<=q_end)return seg[seg_si];
	int mid=(seg_str+seg_end)/2;
	int x=query(2*seg_si+1,seg_str,mid,q_str,q_end);
	int y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	return max(x,y);
}

int main()
{
	int n,q;
	while(scanf("%d",&n) and n)
	{
		scanf("%d",&q);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&num[i]);
			mp[num[i]]++;
		}
		int temp=INT_MIN,k;
		for(int i=0;i<n;++i)
		{
			int x=mp[num[i]];
			cnt[i]=x;
			if(num[i]!=temp)
			{
				k=i;
				temp=num[i];
			}
			start[i]=k;
		}		
		bld_segtree(0,0,n-1);
		for(int i=0;i<q;++i)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(num[l-1]!=num[r-1])
			{
				int s=start[l-1]+cnt[l-1];
				int cnt1=s-l+1;
				int cnt2=r-start[r-1];
				int cnt3=query(0,0,n-1,s,start[r-1]-1);
				int ans=max(max(cnt1,cnt2),cnt3);
				printf("%d\n",ans);
			}
			else
			{
				printf("%d\n",r-l+1);
			}
		}
		memset(seg,0,sizeof(seg));
		memset(cnt,0,sizeof(cnt));
		memset(start,0,sizeof(start));
		mp.clear();
	}
}
