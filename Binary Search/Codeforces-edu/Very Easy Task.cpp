//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n,x,y;cin>>n>>x>>y;
	if(n==1)return cout<<min(x,y)<<"\n",0;
	
	auto good=[&](int m)
	{
	    return (m/x)+(m/y)>=n-1;//1 is resarved for non copyable first value
	};
	
	int l=0;//bad
	int r=2e9;//good
	while(r>l+1){
	    int m=(l+r)/2;
	    if(good(m)){
	        r=m;
	        //cout<<l<<" "<<r<<"\n";
	    }
	    else l=m;
	}
	cout<<r+min(x,y)<<"\n";
	return 0;
}

