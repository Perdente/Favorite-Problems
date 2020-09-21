/*https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/*/
//Point Update using segment tree
#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int num[mx];
pair<int,int>seg[4*mx];//odd,even
 
void bld_segtree(int seg_si,int seg_str,int seg_end)
{
	if(seg_str==seg_end)
	{
		if(num[seg_str]&1)seg[seg_si]={1,0};
		else seg[seg_si]={0,1};
		return;
	}
	int mid=(seg_str + seg_end)/2;
	bld_segtree(2*seg_si+1,seg_str,mid);//recurse on the left child
	bld_segtree(2*seg_si+2,mid+1,seg_end);//recurse on the right child
	
	seg[seg_si].first=seg[2*seg_si+1].first+seg[2*seg_si+2].first;
	seg[seg_si].second=seg[2*seg_si+1].second+seg[2*seg_si+2].second;
}
 
int query(int seg_si,int seg_str,int seg_end,int q_str,int q_end,int key)
{
	if(seg_str>q_end or seg_end<q_str)return 0;
	
	if(seg_str>=q_str and seg_end<=q_end)return (key==1?seg[seg_si].second:seg[seg_si].first);
	
	int mid=(seg_str+seg_end)/2; 
	
	int x=query(2*seg_si+1,seg_str,mid,q_str,q_end,key);
	int y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end,key);
	return x+y;
}
 
void update(int seg_si,int seg_str,int seg_end,int q_ind,int value)
{
	if(seg_str==seg_end)
	{
		if(num[seg_str] % 2)
		{
			seg[seg_si]={0,1};	
		}
		else
		{
			seg[seg_si]={1,0};
		}
		num[seg_str]=value;return;
	}
	int mid=(seg_str+seg_end)/2;
	
	if(q_ind<=mid)update(2*seg_si+1,seg_str,mid,q_ind,value);
	else update(2*seg_si+2,mid+1,seg_end,q_ind,value);
	
	seg[seg_si].first=seg[2*seg_si+1].first+seg[2*seg_si+2].first;
	seg[seg_si].second=seg[2*seg_si+1].second+seg[2*seg_si+2].second;
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>num[i];
	}
	bld_segtree(0,0,n-1);
 
	int q;cin>>q;
	while(q--)
	{
		int x,l,r;
		cin>>x>>l>>r;
		if(x==0)
		{
			if((num[l-1]%2)!=r%2)update(0,0,n-1,l-1,r);
		}
		else
		{
			int ans=query(0,0,n-1,l-1,r-1,x);
			cout<<ans<<endl;
		}
	}
	
}
