//https://www.spoj.com/problems/BUGLIFE/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>>graph;
vector<int>color;
int c=1;
void Malena(){
	int n,m;cin>>n>>m;
	graph.resize(n+1);
	color.resize(n+1);
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
		graph[i].clear();
		color[i]=-1;
	}
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		if(graph[i].size() and color[i]==-1){
			dfs(i,0);
		}
	}
	cout<<"Scenario #"<<c++<<":\n";
	cout<<(flag?"No suspicious bugs found!":"Suspicious bugs found!")<<'\n';
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
