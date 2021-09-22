/*
we need to count the number of elements of each connected component
So, we traverse whole component via bfs and store each node 
the size of the component
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,m;cin>>n>>m;
	vector<int> edges[n+1],ans(n);
	vector<bool> vis(n+1);
	while(m--){
		int x;cin>>x;
		vector<int> v(x);
		for(int i=0;i<x;++i){
			cin>>v[i];v[i]--;
			if(i){
				edges[v[i]].push_back(v[i-1]);
				edges[v[i-1]].push_back(v[i]);
			}
		}
	}
	for(int i=0;i<n;++i){
		if(!vis[i]){
			vector<int> component;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				if(vis[u])continue;
				vis[u]=true;
				component.push_back(u);
				for(auto v:edges[u]){
					if(vis[v])continue;
					q.push(v);
				}
			}
			for(auto ele:component){
				ans[ele]=(int)component.size();
			}
		}
	}
	for(auto it:ans){
		cout<<it<<" ";
	}
	cout<<'\n';
	
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
