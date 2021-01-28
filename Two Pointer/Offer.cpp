//https://codeforces.com/gym/102942/problem/F
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;

signed main()
{
	int t;cin>>t;
	while(t--)
	{
	    int n,k;cin>>n>>k;
	    vector<int>v(n);
	    for(int i=0;i<n;++i)cin>>v[i];
	    int left=0,cost=0,ans=-1;
	    map<int,int>fre;
	    for(int right=0;right<n;++right)
	    {
	        if(fre[v[right]]==0){
	            cost+=v[right];
	        }
	        fre[v[right]]++;
	        while(cost>k)
	        {
	            fre[v[left]]--;
	            if(fre[v[left]]==0)cost-=v[left];
	            left++;
	        }
	        
	        ans=max(ans,right-left+1);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
