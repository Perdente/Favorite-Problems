//connected components + sizeof the same set
//https://www.codechef.com/problems/FIRESC

/*
input:
6 3
1 2
3 4
5 6

output:3 8
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+1,mod=1e9+7;
vector<vector<int>>graph(N);
vector<bool>vis(N);
vector<int>dis(N);
void Malena(){
	int n,m;cin>>n>>m;
	for(int i=0;i<=n;++i){
		graph[i].clear();
		dis[i]=0;
		vis[i]=false;
	}
	while(m--){
		int u,v;cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int c=0;
	function<void(int)>dfs=[&](int u)->void{
		vis[u]=true;
		c++;
		for(auto v:graph[u]){
			if(!vis[v]){
				vis[v]=true;
				dis[v]=dis[u]+1;
				dfs(v);
			}
		}
	};
	int cnt=0,ans=1;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			cnt++;
			dfs(i);
			ans=(ans%mod * c%mod)%mod;
			c=0;
		}
	}
	cout<<cnt<<" "<<ans<<'\n';
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
