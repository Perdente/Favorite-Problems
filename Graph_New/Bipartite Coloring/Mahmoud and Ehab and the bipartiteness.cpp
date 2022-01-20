// https://codeforces.com/contest/862/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void malena(){
    int n; cin >> n;
    vector<int> tree[n + 1], color(n + 1, -1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        tree[u]. push_back(v);
        tree[v]. push_back(u);
    }
    function< void(int, int)>dfs = [&](int u, int col) -> void {
      color[u] = col;
      for(auto v: tree[u]) {
        if(color[v] == -1) {
          dfs(v, col ^ 1);
        }
      }
    };
    dfs(1, 0);
    int left_st = count(color.begin(), color.end(), 0);
    int right_st = count(color.begin(), color.end(), 1);
    cout << left_st * right_st - (n - 1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c = 0;
    t = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case " << ++c <<": ";
        malena();
    }
    return 0;
}
