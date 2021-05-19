//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/containers-of-choclates-1/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+5;
vector<vector<int>>graph(N);
vector<int>color(N);
int cnt=0,cnt1=0,c=1;
void dfs(int u,int current_color){
	color[u]=current_color;
	current_color==0?cnt++:cnt1++;
	for(auto v:graph[u]){
		if(color[v]==-1)dfs(v,current_color^1);
	}
}

void Malena(){
	int n;cin>>n;
	int ma=0,ans=0;
	for(int i=0;i<N;++i){
		graph[i].clear();
		color[i]=-1;
	}
	for(int i=1;i<=n;++i){
		int u,v;cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);	
		ma=max({ma,u,v});	
	}
	cnt=0,cnt1=0;
	for(int i=0;i<N;++i){
		if(graph[i].size() and color[i]==-1){
			dfs(i,0);
			ans+=max(cnt,cnt1);cnt=0,cnt1=0;
		}
	}
	 cout << "Case " << c++ << ": " << ans << endl;

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
