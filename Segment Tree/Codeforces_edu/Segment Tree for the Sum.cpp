//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;

struct segtree{
    int size;
    vector<int>sums;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        sums.assign(2*size,0LL);
    }
    
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        int m=lx+(rx-lx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        int m=lx+(rx-lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    
    int sum(int l,int r,int x,int lx,int rx){
        if(lx>=r or l>=rx) return 0;
        if(lx>=l and rx<=r) return sums[x];
        int m=lx+(rx-lx)/2;
        int ls=sum(l,r,2*x+1,lx,m);
        int rs=sum(l,r,2*x+2,m,rx);
        return ls+rs; 
    }
    
    int sum(int l,int r){
        return sum(l,r,0,0,size);
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
	        cout<<st.sum(l,r)<<"\n";
	    }
	}
	return 0;
}

