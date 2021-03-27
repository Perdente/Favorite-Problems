//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	double c;cin>>c;
	auto good=[&](double x)
	{
	    return x*x+sqrt(x)>=c;
	};
	double l=0,r=1e10;
	cout<<setprecision(10);
	for(int i=0;i<100;++i){
	    double m=(l+r)/2;
	    if(good(m)) r=m;
	    else l=m;
	}
	cout<<r<<endl;
	return 0;
}

