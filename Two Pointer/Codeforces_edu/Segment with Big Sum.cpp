//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n;cin>>n;
	int s;cin>>s;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	int l=0,sum=0,ans=INT_MAX;
	for(int r=0;r<n;++r)
	{
	    sum+=v[r];
	    while(sum-v[l]>=s){
	        sum-=v[l];
	        l++;
	    }
	    if(sum>=s)ans=min(ans,r-l+1);
	}
	if(ans==INT_MAX)ans=-1;
	cout<<ans<<"\n";
	return 0;
}

