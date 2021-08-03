
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
void Malena(){
	int n,m;cin>>n>>m;
	vector<vector<int>>graph(n+1);
	vector<int>color(n+1,-1);
	vector<pair<int,int>>vp(m+1);
	for(int i=1;i<=m;++i){
		int u,v;cin>>u>>v;
		vp[i]={u,v};
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bool flag=true;
	function<void(int,int)>dfs=[&](int u,int col)->void{
		color[u]=col;
		for(auto v:graph[u]){
			if(color[v]==col)flag=false;
			if(color[v]==-1){
				dfs(v,col^1);
			}
		}
	};
	for(int i=1;i<=n;++i){
		if(color[i]==-1)dfs(i,0);
	}
	if(flag){
		cout<<"Yes\n";
		for(int i=1;i<=m;++i){
			// cout<<(s.count(vp[i]));
			int u=vp[i].first;
			int v=vp[i].second;
			if(!color[u])cout<<0;
			else cout<<1;
		}	
		cout<<endl;
	}else{
		cout<<"No\n";
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
