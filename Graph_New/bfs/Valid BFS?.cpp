//https://codeforces.com/contest/1037/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
void Malena(){
	int n;cin>>n;
	vector<int> adj[n+1];
	vector<bool> vis(n+1);
	vector<int> path(n),ans,ord(n+1);
	for(int i=0;i<n-1;++i){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}
	for(int i=0;i<n;++i){
		cin>>path[i];
		ord[path[i]]=i;
	}
	for(int i=1;i<=n;++i){
		sort(adj[i].begin(), adj[i].end(),[&](int x,int y){
			return ord[x]<ord[y];
		});
	}
	
	auto bfs=[&](int snode){
		queue<int> q;
		q.push(snode);
		while(!q.empty()){
			int u=q.front();
			ans.push_back(u);
			vis[u]=true;
			q.pop();
			for(auto v:adj[u]){
				if(!vis[v]){
					q.push(v);
				}
			}
		}
	};
	bfs(1);
	cout<<((ans==path)?"YES\n":"NO\n");
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
