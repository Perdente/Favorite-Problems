//https://www.spoj.com/problems/AIBOHP/
#include<bits/stdc++.h>
using namespace std;
#define N 6105
int l[N][N];
int lps(string s,int n)
{
	for(int i=0;i<n;++i)l[i][i]=1;
	for(int len=2;len<=n;++len)
	{
		for(int i=0;i<=n-len+1;++i)
		{
			int j=i+len-1;
			if(s[i]==s[j] and len==2)l[i][j]=2;
			else if(s[i]==s[j])l[i][j]=l[i+1][j-1]+2;
			else l[i][j]=max(l[i][j-1],l[i+1][j]);
		}
	}
	return l[0][n-1];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		int n=s.size();
		cout<<n-lps(s,n)<<endl;
	}
}
