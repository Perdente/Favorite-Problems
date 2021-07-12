//using binary lifting
//https://www.youtube.com/watch?v=dOAxrhAUIhA&t=56s&ab_channel=Errichto
//https://www.spoj.com/problems/LCASQ/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 10005;
const int LOG = 14;

vector<int>children[N];
int up[N][LOG]; // up[v][j] is the 2^j th ancestor of v
int depth[N];

void dfs(int a){
	for(int b:children[a]){
		depth[b]=depth[a]+1;
		up[b][0]=a; // a is the parent of b 
		for(int j=1;j<LOG;++j){
			up[b][j]=up[ up[b][j-1] ][j-1];
		}
		dfs(b);
	}
}
//O(log(n))
int get_lca(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	int k=depth[a]-depth[b];// To get the same depth
	for(int j=LOG-1;j>=0;--j){
		if(k & (1<<j)){
			a=up[a][j]; // parent of a
		}
	}
	if(a==b)return a;

	for(int j=LOG-1;j>=0;--j){ // move both a & b power of 2 as binary lifting 
		if(up[a][j]!=up[b][j]){
			a=up[a][j];
			b=up[b][j];
		}
	}
	return up[a][0];
}
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	for(int v=0;v<n;++v){
		int nodes;cin>>nodes;
		while(nodes--){
			int c;cin>>c;
			children[v].push_back(c);
		}
	}
	dfs(0);
	int q;cin>>q;
	while(q--){
		int x,y;cin>>x>>y;
		cout<<get_lca(x,y)<<'\n';
	}
	return 0;
}
