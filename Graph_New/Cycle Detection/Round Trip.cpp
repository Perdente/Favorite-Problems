//https://cses.fi/problemset/task/1669/
//https://www.youtube.com/watch?v=JoOuju5N-5g&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=45
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
	vector<int> ans;
	function<bool(int,int)>dfs=[&](int u,int par){
		vis[u]=true;
		ans.push_back(u);
		for(auto v:adj[u]){
			if(!vis[v]){
				if(dfs(v,u))return true;
			}
			else if(par!=v){
				ans.push_back(v);
				return true;
			}
		}
		ans.pop_back();
		return false;
	};
 
	for(int node=1;node<=n;++node){
		if(!vis[node] and dfs(node,-1)){
			vector<int> cycle;
			cycle.push_back(ans.back());
			for(int i=ans.size()-2;i>=0;--i){
				cycle.push_back(ans[i]);
				if(ans[i]==ans.back()){
					cout<<cycle.size()<<'\n';
					for(auto it:cycle){
						cout<<it<<" ";
					}
					cout<<endl;
					return;
				}
			}
			//fill(vis.begin(), vis.end(),false);
			//ans.clear();
		}
	}
	cout<<"IMPOSSIBLE\n";
	
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
