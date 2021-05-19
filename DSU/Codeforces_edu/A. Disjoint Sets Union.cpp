//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+5;
int parent[N],depth[N],size[N];

int find_set(int v){
	if(v==parent[v])return v;
	return parent[v]=find_set(parent[v]);
}

bool isSame_set(int a,int b){
	return find_set(a)==find_set(b);
}

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
	for(int i=1;i<=n;++i)make_set(i);
	while(m--){
		string s;cin>>s;
		int u,v;cin>>u>>v;
		if(s=="union"){
			union_set(u,v);
		}else{
			if(isSame_set(u,v))cout<<"Yes\n";
			else cout<<"No\n";
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
