/*http://www.lightoj.com/volume_showproblem.php?problem=1112*/

#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define mx 1000006
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
    seg[seg_si]=seg[2*seg_si+1]+seg[2*seg_si+2];
}
 
long long query(int seg_si,int seg_str,int seg_end,int q_str,int q_end)
{
    if(seg_str>q_end or seg_end<q_str)return 0;
    if(seg_str>=q_str and seg_end<=q_end)return seg[seg_si];
    int mid=(seg_str+seg_end)/2;
    int x=query(2*seg_si+1,seg_str,mid,q_str,q_end);
    int y=query(2*seg_si+2,mid+1,seg_end,q_str,q_end);
    return x+y;
}
 
void update(int seg_si,int seg_str,int seg_end,int q_ind,int value)
{
    if(seg_str==seg_end)
    {
        seg[seg_si]+=value;return;
    }
    int mid=(seg_str+seg_end)/2;
   
    if(q_ind<=mid)update(2*seg_si+1,seg_str,mid,q_ind,value);
    else update(2*seg_si+2,mid+1,seg_end,q_ind,value);
   
    seg[seg_si]=seg[2*seg_si+1]+seg[2*seg_si+2];
}
 
int main()
{
    int t;cin>>t;
    for(int test=1;test<=t;++test)
    {
        printf("Case %d:\n",test);
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&num[i]);
        }
        bld_segtree(0,0,n-1);
        while(q--)
        {
            int x;scanf("%d",&x);
            if(x==1)
            {
                int ind;scanf("%d",&ind);
                int ans=query(0,0,n-1,ind,ind);
                update(0,0,n-1,ind,-ans);
                printf("%d\n",ans);
            }
            else if(x==2)
            {
                int l,r;scanf("%d%d",&l,&r);
                update(0,0,n-1,l,r);
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%d\n",query(0,0,n-1,l,r));
            }
        }
    }
}
