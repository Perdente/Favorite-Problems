//https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
/*
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
        sums.resize(2*size);
    }
    
    void set(int i,int x,int lx,int rx){
        if(rx-lx==1){
        	sums[x]=1;
            return;
        }
        int m=lx+(rx-lx)/2;
        if(i<m){
            set(i,2*x+1,lx,m);
        }else{
            set(i,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    
    void set(int i){
        set(i,0,0,size);
    }
    
    int sum(int x,int l,int r,int lx,int rx){
        if(lx>=r or l>=rx) return 0;
        if(lx>=l and rx<=r) return sums[x];
        int m=lx+(rx-lx)/2;
        int ls=sum(2*x+1,l,r,lx,m);
        int rs=sum(2*x+2,l,r,m,rx);
        return ls+rs; 
    }
    
    int sum(int d){
        return sum(0,d,size,0,size);
    }
};

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n;
	segtree st;
	st.init(n);
	for(int i=0;i<n;++i){
		cin>>m;
		cout<<st.sum(m)<<" ";
		st.set(m-1);
	}
	return 0;
}

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;

typedef int item;

struct segtree{
    int size;
    vector<item>vec;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        vec.resize(2*size);
    }
    
    item NEUTRAL_ELEMENT=0;
    
    item single(int v){
        return v;
    }
    
    item merge(item a,item b){
        return a+b;
    }
    
    void set(int i,int x,int lx,int rx){
        if(rx-lx==1){
            vec[x]=1;
            return;
        }
        int m=lx+(rx-lx)/2;
        if(i<m){
            set(i,2*x+1,lx,m);
        }else{
            set(i,2*x+2,m,rx);
        }
        vec[x]=merge(vec[2*x+1],vec[2*x+2]);
    }
    
    void set(int i){
        set(i,0,0,size);
    }
    
    item sum(int x,int l,int r,int lx,int rx){
        if(lx>=r or l>=rx) return NEUTRAL_ELEMENT;
        if(lx>=l and rx<=r) return vec[x];
        int m=lx+(rx-lx)/2;
        int ls=sum(2*x+1,l,r,lx,m);
        int rs=sum(2*x+2,l,r,m,rx);
        return merge(ls,rs); 
    }
    
    item sum(int d){
        return sum(0,d,size,0,size);
    }
};

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n;
	segtree st;
	st.init(n);
	for(int i=0;i<n;++i){
	    cin>>m;
	    cout<<st.sum(m)<<" ";
	    st.set(m-1);
	}
	
	return 0;
}

