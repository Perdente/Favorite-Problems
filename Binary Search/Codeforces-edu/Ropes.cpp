//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n,k;cin>>n>>k;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	auto good=[&](double m)
	{
	    int tot=0;
	    for(auto &i:v){
	        tot+=(i/m);
	    }
	    return tot>=k;
	};
	double l=0;//l is bad
	double r=1e8;//r is good
	for(int i=0;i<100;++i){
	    double m=(l+r)/2;
	    if(good(m)) l=m;
	    else r=m;
	}
	cout<<setprecision(20)<<r<<endl;
	return 0;
}

