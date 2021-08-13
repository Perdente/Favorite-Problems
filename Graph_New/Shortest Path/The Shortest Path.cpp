//Dijsktra's Algorithm
//https://www.spoj.com/problems/SHPATH/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define inf INT_MAX
#define p pair<int,int>
void Malena(){
	int n;cin>>n;
	vector<p>edge[n+1];
	unordered_map<string,int> mp;
	for(int u=1;u<=n;++u){
		string s;cin>>s;
		mp[s]=u;
		int m;cin>>m;
		while(m--){
			int v,w;cin>>v>>w;
			edge[u].push_back({w,v});
			edge[v].push_back({w,u});
		}
	}	
	priority_queue<p,vector<p>,greater<p>> pq;
	auto Dijsktra=[&](int snode,int enode)->int{
		pq.push({0,snode});
		vector<int> dist(n+1,inf);
		vector<bool> vis(n+1);
		dist[snode]=0;
		while(!pq.empty()){
			int u=pq.top().second;
			pq.pop();
			if(vis[u])continue;
			vis[u]=true;
			for(auto [w,v]:edge[u]){
				if(dist[u]+w<dist[v]){
					dist[v]=dist[u]+w;
					pq.push({dist[v],v});
				}
			}
		}
		return dist[enode];
	};
	
	int q;cin>>q;
	while(q--){
		string start,end;
		cin>>start>>end;
		cout<<Dijsktra(mp[start],mp[end])<<'\n';
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
	cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}


























