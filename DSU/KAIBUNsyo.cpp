//https://atcoder.jp/contests/abc206/tasks/abc206_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e5+5;
int parent[N],sizee[N];

int cnt=0;
int find_set(int v){
	if(v==parent[v])return v;
	return parent[v]=find_set(parent[v]);
}

bool isSame_set(int a,int b){
	return find_set(a)==find_set(b);
}

//union by size
void make_set(int v) {
    for(int i=1;i<=v;++i){
    	parent[i] = i;
    	sizee[i] = 1;
    }
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
    	cnt++;
        if (sizee[a] < sizee[b])
            swap(a, b);
        parent[b] = a;
        sizee[a] += sizee[b];
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
	vector<int>v(n);
	make_set(N-1);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	for(int i=0;i<n;++i){
		int j=n-1-i;
		union_set(v[i],v[j]);
	}
	cout<<cnt<<'\n';
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
