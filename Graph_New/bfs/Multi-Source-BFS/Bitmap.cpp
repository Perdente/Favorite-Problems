// https://www.spoj.com/problems/BITMAP/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void malena(){
    int n, m; cin >> n >> m;
    string grid[n];
    vector<vector<int>> level(n, vector<int> (m));
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int H = n;
    int W = m;
    int ans = 0;

    auto inside = [&](int row,int col) {
        return 0 <= row and row < H and 0 <= col and col < W;
    };

    vector<pair<int,int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> vis(H, vector<bool> (W));
    queue<pair<int, int> > q;
    for(int row = 0; row < H; ++row){
        for(int col = 0; col < W; ++col){
            if(grid[row][col] == '1'){
                vis[row][col] = true;
                q.push({row, col});
            }
        }
    }
    while(! q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(pair<int,int> dir : directions) {
            int new_row = p.first + dir.first;
            int new_col = p.second + dir.second;
            if(inside(new_row,new_col) and !vis[new_row][new_col]){
                vis[new_row][new_col] = true;
                level[new_row][new_col] = level[p.first][p.second] + 1;
                q.push({new_row, new_col});
            }
        }
    }
    for(int row = 0; row < H; ++row){
        for(int col = 0; col < W; ++col){
            cout << level[row][col] << " ";
        }cout << '\n';
    }

}


signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c = 0;
    t = 1;
    cin >> t;
    while(t--) {
        // cout << "Case " << ++c <<": ";
        malena();
    }
    return 0;
}
