//Grid problem using BFS
//https://www.codechef.com/problems/RISK
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int H,W;cin>>H>>W;
	vector<vector<char>>grid(H,vector<char>(W));
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			cin>>grid[i][j];
		}
	}
    auto inside =[&](int row,int col){
        return 0<=row and row<H and 0<=col and col<W;
    };
    vector<pair<int,int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<bool>>vis(H,vector<bool>(W));
    vector<int>regions;
    for(int row=0;row<H;++row){
        for(int col=0;col<W;++col){
        	int cnt=0;
            if(!vis[row][col] and grid[row][col]=='1')
            {
                vis[row][col]=true;
                queue<pair<int,int>>q;
                q.push({row,col});
                while(!q.empty()){
                	cnt++;
                    pair<int,int>p=q.front();
                    q.pop();
                    for(pair<int,int>dir:directions){
                        int new_row=p.first+dir.first;
                        int new_col=p.second+dir.second;
                        if(inside(new_row,new_col) and !vis[new_row][new_col] and grid[new_row][new_col]=='1')
                        {
                            vis[new_row][new_col]=true;
                            q.push({new_row,new_col});
                        }
                            
                    }
                }
            }
            if(cnt>0)regions.push_back(cnt);
        }
    }
    sort(regions.rbegin(),regions.rend());
    int ans=0;
    int n=regions.size();
    for(int i=0;i<n;++i){
    	if(i&1)ans+=regions[i];
    }
    cout<<ans<<'\n';
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
