//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e5+5;
int parent[N],size[N],add[N];

int find_set(int v){
	if(v==parent[v])return v;
	return find_set(parent[v]);
}

int get(int v){
	if(v==parent[v])return add[v];
	return add[v]+get(parent[v]);
}

bool isSame_set(int a,int b){
	return find_set(a)==find_set(b);
}

//union by size
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        add[b]-=add[a];
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
	int n,m,u,v;cin>>n>>m;
	for(int i=1;i<=n;++i)make_set(i);
	while(m--){
		string s;cin>>s;
		if(s=="add"){
			cin>>u>>v;
			add[find_set(u)]+=v;
		}else if(s=="join"){
			cin>>u>>v;
			union_set(u,v);
		}else{
			cin>>u;
			cout<<get(u)<<'\n';
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
