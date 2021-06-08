//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;

struct stack{
    vector<int>s,smin={LLONG_MAX},smax={LLONG_MIN};
    void push(int x){
        s.push_back(x);
        smin.push_back(::min(smin.back(),x));
        smax.push_back(::max(smax.back(),x));
    }  
    int pop(){
        int res=s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }
    bool empty(){
        return s.empty();
    }
    int min(){
        return smin.back();
    }
    int max(){
        return smax.back();
    }
};
::stack s1,s2;
void add(int x){
    s2.push(x);
}
void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
int k;
bool good(){
    int mi=min(s1.min(),s2.min());
    int ma=max(s1.max(),s2.max());
    return ma-mi<=k;
}
signed main()
{
	int n;cin>>n>>k;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	int l=0,res=0;
	for(int r=0;r<n;++r)
	{
	    add(v[r]);
	    while(!good()){
	        remove();
	        l++;
	    }
	    res+=r-l+1;
	}
	cout<<res<<"\n";
	return 0;
}

