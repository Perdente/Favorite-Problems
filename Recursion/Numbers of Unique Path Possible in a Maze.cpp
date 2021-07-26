/*
  [ 1  1  1  1 ]
  [ 1  1  0  1 ]
  [ 0  1  0  1 ]
  [ 1  1  1  1 ]
  ans=4.
 [ 1  1  1  1 ]       [ 1  1  1  1 ]       [ 1  1  1  1 ]       [ 1  1  1  1 ]
 [ 1  1  0  1 ]       [ 1  1  0  1 ]       [ 1  1  0  1 ]       [ 1  1  0  1 ]
 [ 0  1  0  1 ]       [ 0  1  0  1 ]       [ 0  1  0  1 ]       [ 0  1  0  1 ]
 [ 1  1  1  1 ]       [ 1  1  1  1 ]       [ 1  1  1  1 ]       [ 1  1  1  1 ]
 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int r,c;cin>>r>>c;
	vector<vector<int>>mat(r,vector<int>(c));
	vector<vector<bool>>visited(r,vector<bool>(c));
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			cin>>mat[i][j];
		}
	}

	auto inside=[&](int x,int y){
		return 0<=x and x<r and 0<=y and y<c;
	};
	int cnt=0;
	function<void(int,int,int,int)>solve=[&](int si,int sj,int ei,int ej)->void{
		if(inside(si,sj) and mat[si][sj]==1){
			visited[si][sj]=true;
			if(si==ei and sj==ej)cnt++;
			vector<pair<int,int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
			for(pair<int,int>dir:directions){
				int ni=si+dir.first;
				int nj=sj+dir.second;
				if(inside(ni,nj) and mat[ni][nj]==1 and !visited[ni][nj]){
					solve(ni,nj,ei,ej);
					visited[ni][nj]=false;
				}
			}
		}
		return ;
	};
	solve(0,0,r-1,c-1);
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
