//special adj list(vector<set>)
//https://codeforces.com/contest/1549/problem/C
//https://www.youtube.com/watch?v=giodIzHAxV0
// For each query we update the good nodes
// After each query we have a forest of good nodes, and 
// cnt=number of leafs

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,m;
	cin>>n>>m;
	vector<set<int>>adj(n+1);
	while(m--){
		int u,v;cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	int cnt=0;
	vector<bool>good(n+1);//checks if ith node is good or not
	for(int i=1;i<=n;++i){
		if(adj[i].lower_bound(i)==adj[i].end()){//no adjacent node is greater than ith node
			cnt++;
			good[i]=true;
		}
	}
	int q;cin>>q;
	while(q--){
		int x;cin>>x;
		if(x==3){
			cout<<cnt<<endl;
		}else{
			int u,v;cin>>u>>v;
			
			cnt-=(good[u]);//as we already counted the good nodes
			cnt-=(good[v]);

			if(x==1){
				adj[u].insert(v);
				adj[v].insert(u);
			}else{
				adj[u].erase(v);
				adj[v].erase(u);
			}

			if(adj[u].lower_bound(u)==adj[u].end())good[u]=true;
			else good[u]=false;

			if(adj[v].lower_bound(v)==adj[v].end())good[v]=true;
			else good[v]=false;

			cnt+=(good[u]);//check if the good node still good or not
			cnt+=(good[v]);
		}
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
	while(t--)Malena();
	return 0;
}
