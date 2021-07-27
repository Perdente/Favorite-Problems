//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/
//https://www.youtube.com/watch?v=iygT1oD7C_s&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=20&ab_channel=CodeNCode
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e6+1;
vector<int>adj[N],dis(N);
vector<bool>vis(N);

void Malena(){
	int n,k;cin>>n>>k;
	for(int i=0;i<=n;++i){
		adj[i].clear();
		dis[i]=0;
		vis[i]=false;
	}
	vector<pair<int,int>>vp;
	while(k--){
		int a,b;
		string s;
		cin>>a>>s>>b;
		if(s=="="){
			adj[a].push_back(b);
			adj[b].push_back(a);
		}else{
			vp.emplace_back(a,b);
		}
	}

	function<void(int)>dfs=[&](int u)->void{
		vis[u]=true;
		for(auto v:adj[u]){
			if(!vis[v]){
				vis[v]=true;
				dfs(v);
			}
		}
	};
	int cnt=0;
	vector<int>cc(n+1);//connected components
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			cnt++;
			dfs(i);
		}
		cc[i]=cnt;
	}
	for(auto it:vp){
		int u=it.first,v=it.second;
		if(cc[u]==cc[v]){
			cout<<"NO\n";return;
		}
	}
	cout<<"YES\n";
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
