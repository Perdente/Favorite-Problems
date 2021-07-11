//https://atcoder.jp/contests/abc126/tasks/abc126_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+5;
vector<pair<int,int>>graph[N];
vector<int>color(N);
void Malena(){
	int n,m;cin>>n;
	function<void(int,int,int)>dfs=[&](int u,int pre_col,int new_col)->void{
		color[u]=new_col;
		for(auto v:graph[u]){
			if(v.first!=pre_col){
				dfs(v.first,u,new_col^(v.second&1));
			}
		}
	};
	for(int i=0;i<n-1;++i){
		int x,y,w;cin>>x>>y>>w;
		graph[x].push_back({y,w});
		graph[y].push_back({x,w});
	}
	dfs(1,0,0);
	for(int i=1;i<=n;++i){
		cout<<color[i]<<'\n';
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
