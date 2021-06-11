//https://www.spoj.com/problems/MATGAME/
//https://discuss.codechef.com/t/spoj-problem-matgame-game-theory/3557/2
//https://codeforces.com/blog/entry/2034
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
void Malena(){
	int n,m;cin>>n>>m;
	vector<vector<int>>mat(n,vector<int>(m));
	
	auto grundy=[&](vector<int> u)->int{
		int cur=0;
		for(int i=0;i<m;++i){
			if(u[i]>cur){
				cur=u[i];
			}else{
				cur=u[i]-1;
			}
		}
		return cur;
	};
	vector<int>v(n);
	for(int i=0;i<n;++i){
		vector<int>u(m);
		for(int j=0;j<m;++j){
			cin>>mat[i][j];
			u[j]=mat[i][j];
		}
		reverse(u.begin(),u.end());
		v[i]=grundy(u);
	}
	int x=0;
	for(auto &i:v){
		x^=i;
	}
	cout<<(x?"FIRST":"SECOND")<<'\n';
 
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
 
