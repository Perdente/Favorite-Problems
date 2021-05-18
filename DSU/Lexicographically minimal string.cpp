//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/lexicographically-minimal-string-6edc1406/
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
		if(a>b)swap(a,b);
		//if(depth[a]>depth[b])swap(a,b);
		parent[b]=a;
		//if(depth[a]==depth[b])depth[a]++;
	}
}

void Malena(){
	string s,t,w;cin>>s>>t>>w;
	int n=s.size();
	for(int i=0;i<n;++i){
		make_set(s[i]-'a'+1);
		make_set(t[i]-'a'+1);
	}
	// for(int i=1;i<=26;++i){
	// 	cout<<parent[i]<<' ';
	// }
	// cout<<endl;
	for(int i=0;i<n;++i){
		union_set(s[i]-'a'+1,t[i]-'a'+1);
	}

	// for(int i=1;i<=26;++i){
	// 	cout<<parent[i]<<' ';
	// }
	int m=w.size();
	for(int i=0;i<m;++i){
		if(find_set(w[i]-'a'+1))
			cout<<(char)(find_set(w[i]-'a'+1)+96);
		else 
			cout<<w[i];
	}
	cout<<'\n';
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
