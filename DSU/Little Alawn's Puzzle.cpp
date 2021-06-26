//https://codeforces.com/problemset/problem/1534/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=4e5+5,mod=1e9+7;
int parent[N],depth[N],sizE[N];

int find_set(int v){
	if(v==parent[v])return v;
	return parent[v]=find_set(parent[v]);
}

bool isSame_set(int a,int b){
	return find_set(a)==find_set(b);
}

//union by size
void make_set(int v) {
    parent[v] = v;
    sizE[v] = 1;
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizE[a] < sizE[b])
            swap(a, b);
        parent[b] = a;
        sizE[a] += sizE[b];
    }
}

//union by rank based on depth of the tree
// void make_set(int v){
// 	parent[v]=v;
// 	depth[v]=0;
// }

// void union_set(int a,int b){
// 	a=find_set(a);
// 	b=find_set(b);
// 	if(a!=b){
// 		if(depth[a]<depth[b])swap(a,b);
// 		parent[b]=a;
// 		if(depth[a]==depth[b])depth[a]++;
// 	}
// }



void Malena(){
  int n;cin>>n;
  for(int i=1;i<=n;++i)make_set(i);
  vector<int>v(n),u(n);
  for(int i=0;i<n;++i)cin>>v[i];
  	for(int i=0;i<n;++i)cin>>u[i];
  for(int i=0;i<n;++i){
  	union_set(v[i],u[i]);
  }
  int cnt=0;
  for(int i=1;i<=n;++i){
  	if(i==find_set(i))cnt++;
  }
  int ans=1;
  for(int i=0;i<cnt;++i){
  	ans=(ans*2)%mod;
  }
  cout<<ans<<'\n';
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
