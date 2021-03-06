//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;


struct item{
    int m,c;
};

struct segtree{
    int size;
    vector<item>Mi;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        Mi.resize(2*size);
    }
    
    item merge(item a,item b){
        if(a.m<b.m) return a;
        if(a.m>b.m) return b;
        return {a.m,a.c+b.c};
    }
    
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            Mi[x]={v,1};
            return;
        }
        int m=lx+(rx-lx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        Mi[x]=merge(Mi[2*x+1],Mi[2*x+2]);
    }
    
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                Mi[x]={a[lx],1};
            }
            return;
        }
        int m=lx+(rx-lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        Mi[x]=merge(Mi[2*x+1],Mi[2*x+2]);
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    
    item mini(int l,int r,int x,int lx,int rx){
        if(lx>=r or l>=rx) return {INT_MAX,0};
        if(lx>=l and rx<=r) return Mi[x];
        int m=lx+(rx-lx)/2;
        item ls=mini(l,r,2*x+1,lx,m);
        item rs=mini(l,r,2*x+2,m,rx);
        return merge(ls,rs);
    }
    
    item mini(int l,int r){
        return mini(l,r,0,0,size);
    }
};

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	segtree st;
	st.init(n);
	vector<int>a(n);
	for(int i=0;i<n;++i)
	    cin>>a[i];
	st.build(a);
	while(m--){
	    int op;cin>>op;
	    if(op==1){
	        int i,v;cin>>i>>v;
	        st.set(i,v);
	    }else{
	        int l,r;cin>>l>>r;
	        auto res=st.mini(l,r);
	        cout<<res.m<<" "<<res.c<<"\n";
	    }
	}
	return 0;
}

