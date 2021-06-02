//https://www.spoj.com/problems/PT07Y/
/*For tree:-
Number of connected components=1.
Number of edges should be 1 less than number of vertices.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e4+5;
vector<vector<int>>graph(N);
vector<int>color(N);
void Malena(){
	int n,m;cin>>n>>m;
	bool flag=true;
	function<void(int,int)>dfs=[&](int u,int current_color)->void{
		color[u]=current_color;
		for(auto v:graph[u]){
			if(color[v]==current_color)flag=false;
			if(color[v]==-1){
				dfs(v,current_color^1);
			}
		}
	};
	for(int i=0;i<N;++i){
		graph[i].clear();color[i]=-1;
	}
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=0;i<N;++i){
		if(graph[i].size() and color[i]==-1){
			dfs(i,0);
		}
	}
	for(int i=1;i<=n;++i){
		if(color[i]==-1)flag=false;
	}
	cout<<(flag?"YES":"NO")<<'\n';
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
