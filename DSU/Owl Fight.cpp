//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+5,MOD=1e9+7;
int parent[N],depth[N],size[N],arr[N];
int mod(int M){return (M % MOD + MOD)%MOD;}
//union by size
// void make_set(int v) {
//     parent[v] = v;
//     size[v] = 1;
// }
 
// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (size[a] < size[b])
//             swap(a, b);
//         parent[b] = a;
//         size[a] += size[b];
//     }
// }
 
int find_set(int v){
	if(v!=parent[v])parent[v]=find_set(parent[v]);
	return parent[v];
}
 
bool isSame_set(int a,int b){
	return find_set(a)==find_set(b);
}
 
//union by rank based on depth of the tree
void make_set(int v){
	parent[v]=v;
	depth[v]=0;
}
 
void union_set(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(depth[a]<depth[b])swap(a,b);
		parent[b]=a;
		if(depth[a]==depth[b])depth[a]++;
	}
}
 
 
void Malena(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i){
		make_set(i);
	}
	int a,b;
	while(m--){
		cin>>a>>b;
		union_set(a,b);
	}
	unordered_map<int,int>mp;
	for(int i=1;i<=n;++i){
		mp[find_set(i)]=i;
	}
	for(int i=1;i<=n;++i){
		arr[i]=mp[find_set(i)];
	}

	int q;cin>>q;
	while(q--){
		cin>>a>>b;
		if(isSame_set(a,b))cout<<"TIE\n";
		else{
			if(arr[a]>arr[b])cout<<a<<'\n';
			else cout<<b<<'\n';
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
	while(t--){
		Malena();
	}
	return 0;
}
