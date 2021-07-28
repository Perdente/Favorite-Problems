//https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
#include<bits/stdc++.h>
using namespace std;

void Malena(){
	int n;cin>>n;
	vector<vector<int>>mat(n,vector<int>(n,-1));
	auto inside=[&](int x,int y){
		return 0<=x and x<n and 0<=y and y<n;
	};
	function<bool(int,int,int)>solve=[&](int si,int sj,int move)->bool{
		mat[si][sj]=move;
		if(move==n*n){
			return true;
		}
		vector<pair<int,int>>directions{{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};//The knight moves
		for(pair<int,int>dir:directions){
			int ni=si+dir.first;
			int nj=sj+dir.second;
			if(inside(ni,nj) and mat[ni][nj]==-1){
				if(solve(ni,nj,move+1)) return true;
				mat[ni][nj]=-1;

			}
		}
		return false;
	};
	
	if(solve(0,0,1)){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<mat[i][j]<<" ";
			}cout<<endl;
		}
	}else{
		cout<<"Impossible\n";
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
