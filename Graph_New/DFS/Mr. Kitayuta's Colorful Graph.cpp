//https://codeforces.com/problemset/problem/505/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define eb emplace_back

void Malena(){
	int n,m;cin>>n>>m;
	vector<vector<pair<int,int>>>adj(n+1);
	vector<bool>vis(n+1);
	while(m--){
		int u,v,c;cin>>u>>v>>c;
		adj[u].eb(c,v);
		adj[v].eb(c,u);
	}
	function<void(int,int)>dfs=[&](int col,int u)->void{
		vis[u]=true;
		for(auto v:adj[u]){
			if(!vis[v.second] and col==v.first){
				dfs(col,v.second);
			}
		}
	};

	int q;cin>>q;
	while(q--){
		int cnt=0;
		int u,v;cin>>u>>v;
		for(int i=1;i<=100;++i){
			fill(vis.begin(), vis.end(),false);
			dfs(i,u);
			cnt+=vis[v];
		}
		cout<<cnt<<endl;
	}
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
