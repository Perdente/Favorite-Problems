//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n,m;cin>>n>>m;
	vector<int>v(n),u(m);
	map<int,int>mp;
	for(int &i:v)cin>>i;
	for(int &i:u)cin>>i,mp[i]++;
	int i=0,ans=0;
	for(int j=0;j<m;++j){
	    int cnt=0;
	    while(i<n) 
	    {
	        if(v[i]==u[j])cnt++;
	        else if(v[i]>u[j])break;
	        i++;
	    }
	    ans+=cnt*mp[u[j]];
	}
	cout<<ans<<endl;
	cout<<"\n";
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n,m;cin>>n>>m;
	vector<int>v(n),u(m);
	map<int,int>mp;
	for(int &i:v)cin>>i;
	for(int &i:u)cin>>i,mp[i]++;
	int ans=0;
	for(int i=0;i<n;++i){
	    ans+=mp[v[i]];
	}
	cout<<ans<<endl;
	cout<<"\n";
	return 0;
}*/
