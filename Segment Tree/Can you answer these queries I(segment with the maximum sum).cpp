//https://codeforces.com/edu/course/2/lesson/4/2
//https://www.spoj.com/problems/GSS1/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;


struct item{
    int seg,pref,suf,sum;
};

struct segtree{
    int size;
    vector<item>vec;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        vec.resize(2*size);
    }
    
    item NEUTRAL_ELEMENT={INT_MIN,INT_MIN,INT_MIN,INT_MIN};
    
    item single(int v){
        if(v>INT_MIN){
            return {v,v,v,v};
        }else{
            return{INT_MIN,INT_MIN,INT_MIN,v};
        }
    }
    
    item merge(item a,item b){
        return{
            max({a.seg,b.seg,a.suf+b.pref}),
            max({a.pref,a.sum+b.pref}),
            max({b.suf,b.sum+a.suf}),
            a.sum+b.sum
        };
    }
    
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            vec[x]=single(v);
            return;
        }
        int m=lx+(rx-lx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        vec[x]=merge(vec[2*x+1],vec[2*x+2]);
    }
    
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                vec[x]=single(a[lx]);
            }
            return;
        }
        int m=lx+(rx-lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        vec[x]=merge(vec[2*x+1],vec[2*x+2]);
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    
    item fun(int l,int r,int x,int lx,int rx){
        if(lx>=r or l>=rx) return NEUTRAL_ELEMENT;
        if(lx>=l and rx<=r) return vec[x];
        int m=lx+(rx-lx)/2;
        item ls=fun(l,r,2*x+1,lx,m);
        item rs=fun(l,r,2*x+2,m,rx);
        return merge(ls,rs);
    }
    
    item fun(int l,int r){
        return fun(l,r,0,0,size);
    }
};

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n;
	segtree st;
	st.init(n);
	vector<int>a(n);
	for(int i=0;i<n;++i)
	    cin>>a[i];
	st.build(a);
	cin>>m;
	while(m--){
	   int l,r;cin>>l>>r;l--,r--;
	   cout<<st.fun(l,r+1).seg<<"\n";
    }
	return 0;
}
