//https://atcoder.jp/contests/abc231/tasks/abc231_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void malena(){
	int n, m; cin >> n >> m;
	vector<int> adj[n+1];
	vector<bool> vis(n+1);
	map <int,int> mp;
	bool possib = true;
	for(int i=0;i<m;++i){
	  int u,v;cin>>u>>v;
	  mp[u]++, mp[v]++;
	  if(mp[u] == 3 or mp[v] == 3){
	  	possib = false;
	  }
	  adj[u].push_back(v);
	  adj[v].push_back(u);
	}
	function<bool(int,int)>dfs=[&](int u, int par){
	  vis[u]=true;
	  for(auto v : adj[u]){
	    if(! vis[v]){
	      if(dfs(v, u)) return true;
	    } else if(v != par){
	    	return true;
	    }
	  }
	  return false;
	};
	bool foundcycle = false;
	for(int i=1 ;i<=n;++i){
		if(!vis[i]){
			if(dfs(i,-1)){
				foundcycle = true;
			}
		}
	}
	if(!possib or foundcycle){
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	t=1;
	// cin>>t;
	while(t--) malena();
	return 0;
}
