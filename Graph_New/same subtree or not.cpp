/*
5 4
1 2
1 3
3 4
3 5
3
3 5
2 3
1 4


node 3 and 5 are in same subtree
node 2 and 3 are in different subtree
node 1 and 4 are in same subtree
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+1;
vector<vector<int>>graph(N);
vector<int>in(N),out(N);
vector<bool>vis(N);
void Malena(){
	int n,m;cin>>n>>m;
	while(m--){
		int u,v;cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int cnt=1;
	function<void(int)>dfs=[&](int u)->void{
		vis[u]=true;
		in[u]=cnt++;
		for(auto v:graph[u]){
			if(!vis[v])dfs(v);
		}
		out[u]=cnt++;
	};
	dfs(1);
	int q;cin>>q;
	while(q--){
		int x,y;cin>>x>>y;
		if(out[x]>out[y]){
			cout<<"node "<<x<<" and "<<y<<" are in same subtree";
		}else{
			cout<<"node "<<x<<" and "<<y<<" are in different subtree";
		}
		cout<<endl;
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
