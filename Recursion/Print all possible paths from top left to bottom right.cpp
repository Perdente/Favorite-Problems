/*
2 3
1 2 3 
4 5 6
ans:
1 4 5 6 
1 2 5 6 
1 2 3 6 

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
		if(inside(si,sj)){
			visited[si][sj]=true;
			if(si==ei and sj==ej){
				for(int i=0;i<r;++i){
					for(int j=0;j<c;++j){
						if(visited[i][j])cout<<mat[i][j]<<" ";
					}
				}
				cout<<endl;
			}
			vector<pair<int,int>>directions{{1,0},{0,1}};//we only have to move right and down
			for(pair<int,int>dir:directions){
				int ni=si+dir.first;
				int nj=sj+dir.second;
				if(inside(ni,nj) and !visited[ni][nj]){
					solve(ni,nj,ei,ej);
					visited[ni][nj]=false;
				}
			}
		}
		return ;
	};
	solve(0,0,r-1,c-1);
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
