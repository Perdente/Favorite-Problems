//https://atcoder.jp/contests/abc209/tasks/abc209_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e5+5;
vector<vector<int>>graph;
vector<bool>visited;
vector<int>color;
void Malena(){
	int n,m;cin>>n>>m;
	graph.resize(n+1);
	visited.resize(n+1);
	color.resize(n+1);
	for(int i=1;i<=n;++i){
		graph[i].clear();
		color[i]=-1;
	}
	function<void(int,int)>dfs=[&](int u,int col)->void{
		color[u]=col;
		for(auto v:graph[u]){
			if(color[v]==-1)dfs(v,col^1);
		}
	};
	for(int i=0;i<n-1;++i){
		int x,y;cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1,0);
	while(m--){
		int x,y;cin>>x>>y;
		cout<<(color[x]==color[y]?"Town":"Road")<<'\n';
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
