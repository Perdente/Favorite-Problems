//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() or grid[0].empty()) return 0;
        
        int H=grid.size();
        int W=grid[0].size();
        int ans=0;
        auto inside =[&](int row,int col){
            return 0<=row and row<H and 0<=col and col<W;
        };
        
        vector<pair<int,int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<bool>>vis(H,vector<bool>(W));
        for(int row=0;row<H;++row){
            for(int col=0;col<W;++col){
                if(!vis[row][col] and grid[row][col]=='1')
                {
                    ans++;
                    vis[row][col]=true;
                    queue<pair<int,int>>q;
                    q.push({row,col});
                    while(!q.empty()){
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
            }
        }
        return ans;
    }
};
