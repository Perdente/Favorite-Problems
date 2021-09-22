//https://codeforces.com/gym/317667/problem/D
// check the bipartitness of a graph
// if you can't assaign a node a color then it's -1
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,m;cin>>n>>m;
	vector<int> adj[n+1],color(n+1);
	vector<bool> vis(n+1);
	for(int i=1;i<=n;++i){
		adj[i].clear();color[i]=-1;
	}
	while(m--){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool flag=true;
	function<void(int,int)>dfs=[&](int u,int col)->void{
	  color[u]=col;
	  for(auto v:adj[u]){
	    if(color[v]==col)flag=false;
	    if(color[v]==-1){
	      dfs(v,col^1);
	    }
	  }
	};
	for(int i=1;i<=n;++i){
		if(adj[i].size() and color[i]==-1){
			dfs(i,0);
		}
	}
	if(flag){
		vector<int> a,b;
		for(int i=1;i<=n;++i){
			if(color[i]==0)a.push_back(i);
			else if(color[i]==1)b.push_back(i);
			
		}
		cout<<a.size()<<'\n';
		for(auto it:a)cout<<it<<" ";
		cout<<'\n';

		cout<<b.size()<<'\n';
		for(auto it:b)cout<<it<<" ";
		cout<<'\n';
	}else{
		cout<<-1<<'\n';
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
