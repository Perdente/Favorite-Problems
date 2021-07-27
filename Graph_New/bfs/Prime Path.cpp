//https://www.spoj.com/problems/PPATH/
//https://www.youtube.com/watch?v=eYf4NFc2s1w&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=19&ab_channel=CodeNCode
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+1;
vector<int> p;
vector<int>dis(N);
vector<bool>vis(N);
vector<int> adj[N];
	
bool isPrime(int n){
	for(int i=2;i*i<=n;++i){
		if(n%i==0)return false;
	}
	return true;
}
void make_graph(){
	for(int i=1000;i<=9999;++i){
		if(isPrime(i)){
			p.push_back(i);
		}
	}
	auto possible=[&](int x,int y){
		int cnt=0;
		while(x){
			if(x%10!=y%10)cnt++;
			x/=10,y/=10;
		}
		return (cnt==1);
	};
	int n=p.size();
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if(possible(p[i],p[j])){
				int u=p[i],v=p[j];
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
	}
}
void Malena(){
	int a,b;cin>>a>>b;
	for(int i=1000;i<=9999;++i){
		dis[i]=-1;
		vis[i]=false;
	}
	auto bfs=[&](int s){
		queue<int>q;
		q.push(s);
		vis[s]=true;
		dis[s]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:adj[u]){
				if(!vis[v]){
					vis[v]=true;
					dis[v]=1+dis[u];
					q.push(v);
				}
			}
		}
	};
	bfs(a);
	if(dis[b]==-1){
		cout<<"Impossible\n";
	}else{
		cout<<dis[b]<<'\n';
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
	cin>>t;
	make_graph();
	while(t--){
		Malena();
	}
	return 0;
}
