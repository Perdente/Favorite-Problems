//https://codeforces.com/contest/977/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
void Malena(){
	int n,m;cin>>n>>m;
	vector<int> adj[n+1];
	vector<bool> vis(n+1);
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}
	bool found_cycle=true;
	function<void(int)>dfs=[&](int u){
		vis[u]=true;
		if(adj[u].size()!=2) found_cycle=false;//checks if degree is 2
		for(auto v:adj[u]){
			if(!vis[v]){
				dfs(v);
			}
		}
	};
 	int cnt=0;
	for(int node=1;node<=n;++node){
		found_cycle=true;
		if(!vis[node]){// checks for each cc
			dfs(node);
			if(found_cycle)cnt++;
		}
	}
	cout<<cnt<<"\n";
	
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
	while(t--){
		Malena();
	}
	return 0;
}
