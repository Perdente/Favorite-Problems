//https://codeforces.com/contest/1498/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e7+5;
int cnt[N];
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;cin>>t;
	while(t--)
	{
	   int n,w;cin>>n>>w;
	   for(int i=0;i<n;++i){
	   	int x;cin>>x;
	   	cnt[x]++;
	   }

	   int ans=0;
	   while(n>0){
	   	  int cur=w;
	   	  for(int i=(1<<20);i>0;(i>>=1)){
		   		while(cnt[i]>0 and cur>=i){
		   			cnt[i]--;
		   			n--;
		   			cur-=i;
		   		}
		   }
		   ans++;
	   }
	   cout<<ans<<"\n";
	}
	return 0;
}
