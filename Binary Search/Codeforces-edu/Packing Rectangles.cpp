//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int w,h,n;cin>>w>>h>>n;
	auto good=[&](int m)
	{
	    return ((m/w)*(m/h))>=n;
	};
	int l=0;//l is bad
	int r=1;//r is bad for now
	while(!good(r))r*=2;//r is smallest good number
	while(r>l+1){
	    int m=(l+r)/2;
	    if(good(m)){
	        r=m;
	    }
	    else l=m;
	}
	cout<<r<<"\n";
	return 0;
}

