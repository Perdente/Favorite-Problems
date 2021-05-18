#include<bits/stdc++.h>
using namespace std;
#define int long long int
int parent[10005],depth[10005],size[10005];

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
