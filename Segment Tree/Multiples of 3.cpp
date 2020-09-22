/*https://www.spoj.com/problems/MULTQ3/*/
// Program to show segment tree to demonstrate lazy
// propagation
#include<bits/stdc++.h>
using namespace std;
#define mx 100005
long long  num[mx];
struct node
{
	long long zero=0,one=0,two=0;
};
node seg[4*mx];
long long lazy[4*mx]={0};

node Shift(node temp,long long time)
{
	for(long long i=0;i<time;++i)
	{
		long long t=temp.two;
		temp.two=temp.one;
		temp.one=temp.zero;
		temp.zero=t;
	}
	return temp;
}

void update(long long seg_si,long long seg_str,long long seg_end,long long q_str,long long q_end)
{
	// If lazy value is non-zero for current node of segment
	// tree, then there are some pending updates. So we need
	// to make sure that the pending updates are done before
	// making new updates. Because this value may be used by
	// parent after recursive calls (See last line of this
	// function)
	if(lazy[seg_si]!=0)//if lazy contains previous value
	{
		// Make pending updates using value stored in lazy
		// nodes
		seg[seg_si]=Shift(seg[seg_si],lazy[seg_si]%3);
		if(seg_str!=seg_end)
		{
			lazy[2*seg_si+1]+=lazy[seg_si];
			lazy[2*seg_si+2]+=lazy[seg_si];
		}
		lazy[seg_si]=0;
	}
	if(seg_str>q_end or seg_end<q_str or seg_str>seg_end) return ;//no overlap
	
	if(seg_str>=q_str and seg_end<=q_end)//total overlap
	{
		seg[seg_si]=Shift(seg[seg_si],1);//update the range
		
		if(seg_str!=seg_end)//if not leaf not then update its children
		{
			lazy[2*seg_si+1]+=1;
			lazy[2*seg_si+2]+=1;
		}
		return ;
	}
	// If not completely in rang, but overlaps, recur for
	// children
	long long mid=(seg_str+seg_end)/2;
	
	update(2*seg_si+1,seg_str,mid,q_str,q_end);
	update(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	
	seg[seg_si].zero=seg[seg_si*2+1].zero+seg[seg_si*2+2].zero;
	seg[seg_si].one=seg[seg_si*2+1].one+seg[seg_si*2+2].one;
	seg[seg_si].two=seg[seg_si*2+1].two+seg[seg_si*2+2].two;
	// And use the result of children calls to update this
	// node
}


void blt_segtree(long long seg_si,long long seg_str,long long seg_end)
{
	if(seg_str>seg_end)return;
	if(seg_str==seg_end)
	{
		seg[seg_si].zero=1;return;
	}
	long long mid=(seg_str + seg_end)/2;
	blt_segtree(2*seg_si+1,seg_str,mid);//recurse on the left child
	blt_segtree(2*seg_si+2,mid+1,seg_end);//recurse on the right child
	
	seg[seg_si].zero=seg[2*seg_si + 1].zero+seg[2*seg_si + 2].zero;
}

long long query(long long seg_si,long long seg_str,long long seg_end,long long q_str,long long q_end)
{
	if(lazy[seg_si]!=0)
	{
		seg[seg_si]=Shift(seg[seg_si],lazy[seg_si]%3);
		
		if(seg_str!=seg_end)
		{
			lazy[2*seg_si+1]+=lazy[seg_si];
			lazy[2*seg_si+2]+=lazy[seg_si];
		}
		lazy[seg_si]=0;
	}
	if(seg_str>q_end or seg_end<q_str or seg_str>seg_end)return 0;
	
	if(seg_str>=q_str and seg_end<=q_end)return seg[seg_si].zero;
	
	long long mid=(seg_str+seg_end)/2;
	long long x=query(2*seg_si+1,seg_str,mid,q_str,q_end);
	long long y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end);
	return x+y;
}

long long getsum(long long n,long long q_str,long long q_end)
{
	if(q_str<0 or q_end>n-1 or q_str>q_end)
	{
		cout<<"Invalid input"<<endl;
		return -1;
	}
	return query(0,0,n-1,q_str,q_end);
}

void updateRange(long long n,long long q_str,long long q_end)
{
	update(0,0,n-1,q_str,q_end);
}

void build(long long n)
{
	blt_segtree(0,0,n-1);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n,q;cin>>n>>q;
	
	build(n);
	
	while(q--)
	{
		long long x,l,r;cin>>x>>l>>r;
		if(x==0)
		{
			updateRange(n,l,r);
		}
		else
		{
			cout<<getsum(n,l,r)<<endl;
		}
	}
}
