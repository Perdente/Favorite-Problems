//https://atcoder.jp/contests/abc211/tasks/abc211_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e5+5,mod=1e9+7;

vector<int>adj[N];
int dis[N],ways[N];
void Malena(){
	int n,m;cin>>n>>m;
	while(m--){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int>q;
	q.push(1);
	dis[1]=0,ways[1]=1;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto u:adj[v]){
			if(!dis[u] or dis[u]>dis[v]){
				if(!dis[u]) q.push(u);
				if(dis[u]>dis[v]+1){
					ways[u]=ways[v];
				}
				else if(dis[u]=dis[v]+1){
					ways[u]+=ways[v];
				}
				dis[u]=dis[v]+1;
				ways[u]%=mod;
			}
		}
	}
	cout<<ways[n]<<'\n';
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
