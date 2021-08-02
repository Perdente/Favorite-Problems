//https://codeforces.com/problemset/problem/580/C
//dfs on tree

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	vector<int>v(n+1),vis(n+1);
	for(int i=1;i<=n;++i)cin>>v[i];
	while(n--){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cnt=0;
	function<void(int,int,int)>dfs=[&](int u,int cc,int mcc)->void{
		if(v[u])cc++;//cc- consecutive cats
		else cc=0;
		mcc=max(mcc,cc);//mcc-maximum consecutive cats
		vis[u]=1;
		bool isleaf=true;
		for(auto v:adj[u]){
			if(!vis[v]){
				dfs(v,cc,mcc);
				isleaf=false;// if a node doesn't have child that's leaf
			}
		}
		if(isleaf and mcc<=m)cnt++;
	};
	dfs(1,0,0);
	cout<<cnt<<'\n';
}

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	t=1;
	//cin>>t;
	while(t--)Malena();
	return 0;
}
