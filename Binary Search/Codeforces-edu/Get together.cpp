//https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A\
/*Min-Max problem*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n;cin>>n;
	vector<long double>x(n),v(n);
	for(int i=0;i<n;++i)
	{
	    cin>>x[i]>>v[i];
	}
	auto good=[&](long double t)
	{
	    long double ma=1e10,mi=-1e10;
	    for(int i=0;i<n;++i){
	        mi=max(mi,x[i]-t*v[i]);
	        ma=min(ma,x[i]+t*v[i]);
	    }
	    return mi<=ma;
	};
	long double l=0,r=1e9+7;
	for(int d=0;d<100;++d){
	    long double m=l+(r-l)/2;
	    if(good(m)){
	        r=m;
	    }
	    else{
	        l=m;
	    }
	}
	cout<<setprecision(20)<<r<<"\n";
	return 0;
}

