//https://codeforces.com/problemset/problem/893/C
// Here, we check each connected component and add the smallest 
// value of each connected component
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,m;cin>>n>>m;
	vector<int> adj[n+1];
	vector<bool> vis(n+1);
	vector<int> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	while(m--){
		int x,y;cin>>x>>y;x--,y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	function<int(int)>dfs=[&](int u)->int{
	  vis[u]=true;
	  int mi=v[u];
	  for(auto d:adj[u]){
	    if(!vis[d]){
	      mi=min(mi,dfs(d));
	    }
	  }
	  return mi;
	};
	int ans=0;
	for(int i=0;i<n;++i){
		if(!vis[i])ans+=dfs(i);
	}
	cout<<ans<<'\n';
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
