//https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B
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
    void build(vector<int>&v,int x,int lx,int rx){
        if(rx-lx==1){
            vec[x]=1;
            return;
        }
        int m=lx+(rx-lx)/2;
        build(v,2*x+1,lx,m);
        build(v,2*x+2,m,rx);
        vec[x]=merge(vec[2*x+1],vec[2*x+2]);
    }
    void build(vector<int>&v){
        build(v,0,0,size);
    }
    
    void update(int i,int d,int x,int lx,int rx){
        if(rx-lx==1){
            vec[x]=d;
            return;
        }
        int m=lx+(rx-lx)/2;
        if(i<m){
            update(i,d,2*x+1,lx,m);
        }else{
            update(i,d,2*x+2,m,rx);
        }
        vec[x]=merge(vec[2*x+1],vec[2*x+2]);
    }
    
    void update(int i,int d){
        update(i,d,0,0,size);
    }
    
    item query(int d,int x,int lx,int rx){
        if(rx-lx==1) return lx;
        int m=lx+(rx-lx)/2;
        if(d<vec[2*x+1])return query(d,2*x+1,lx,m);
        else return query(d-vec[2*x+1],2*x+2,m,rx);
    }
    
    item query(int d){
        return query(d,0,0,size);
    }
};

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n;
	segtree st;
	st.init(n);
	vector<int>v(n),ans(n,0);
	for(int i=0;i<n;++i){
	    cin>>v[i];
	}
	//build segtree setting every element to 1.
	st.build(v);
	for(int i=n-1;i>=0;--i){
	    int pos=st.query(i-v[i]);//query for the elements that can have v[i] ones
	    ans[i]=pos+1;
	    st.update(pos,0);//after finishing the query update each position with zeroes..
	}
	for(auto i:ans)
	    cout<<i<<" ";
	cout<<"\n";
	
	return 0;
}

