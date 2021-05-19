//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=400&mosmsg=Submission+received+with+ID+26415488
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define int long long int
const int N=30;
int parent[N],depth[N],size[N];

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
	memset(parent,0,sizeof(parent));
	memset(size,0,sizeof(size));
	int n,x,y;
	char ch;//cin>>ch;
	scanf(" %c",&ch);
	n=ch-'A'+1;
	for(int i=1;i<=n;++i)make_set(i);
	cin.ignore();
	string s;
	while(getline(cin,s)){
		if(s.empty())break;
		x=s[0]-'A'+1,y=s[1]-'A'+1;
		//printf("%d %d\n", x,y);
		//cout<<x<<" "<<y<<endl;
		union_set(x,y);
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(parent[i]==i)cnt++;
	}
	printf("%d\n", cnt);
	//cout<<cnt;
}



signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	t=1;
	scanf("%d",&t);
	//cin>>t;
	while(t--){
		Malena();
		if(t)cout<<'\n';
	}
	return 0;
}
