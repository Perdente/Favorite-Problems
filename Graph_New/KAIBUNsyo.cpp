//https://atcoder.jp/contests/abc206/tasks/abc206_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e5+5;
vector<vector<int>>graph(N);
vector<bool>visited(N);
void Malena(){
	int n;cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	for(int i=0;i<n;++i){
		int j=n-i-1;
		graph[v[i]].push_back(v[j]);
		graph[v[j]].push_back(v[i]);
	}
	int cnt=0;
	function<void(int)>dfs=[&](int u)->void{
		visited[u]=true;
		for(auto v:graph[u]){
			if(!visited[v]){
				cnt++;
				dfs(v);
			}
		}
	};
	for(int i=0;i<n;++i){
		if(!visited[v[i]]){
			dfs(v[i]);
		}
	}
	cout<<cnt<<'\n';

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
