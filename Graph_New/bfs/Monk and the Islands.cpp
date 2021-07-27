//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,m;cin>>n>>m;
	vector<int>adj[n+1];
	while(m--){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>dis(n+1);
	vector<bool>vis(n+1);
	queue<int>q;
	q.push(1);
	vis[1]=true;
	dis[1]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:adj[u]){
			if(!vis[v]){
				vis[v]=true;
				dis[v]=1+dis[u];
				q.push(v);
			}
		}
	}
	cout<<dis[n]<<'\n';

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
	cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
