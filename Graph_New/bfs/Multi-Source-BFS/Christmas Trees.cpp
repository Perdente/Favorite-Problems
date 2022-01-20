//https://codeforces.com/problemset/problem/1283/D
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void malena(){
    int n, m, x; cin >> n >> m;
    set<int> vis;
    map<int, int> dis;
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        dis[x] = 0;
        q.push(x);
        vis.insert(x);
    }
    int cnt = 0, p = 1, sum = 0;

    while(!q.empty() and cnt < m) {
        int top = q.front();
        q.pop();
        if (cnt < m and !vis.count(top + 1)) {
            vis.insert(top + 1);
            dis[top + 1] = dis[top] + 1;
            q.push(top + 1);
            ans.push_back(top + 1);
            cnt++;
        }

        if (cnt < m and !vis.count(top - 1)) {
            vis.insert(top - 1);
            dis[top - 1] = dis[top] + 1;
            q.push(top - 1);
            ans.push_back(top - 1);
            cnt++;
        }
    }
    for(auto [key, value]: dis) {
        sum += value;
    }
    cout << sum << '\n';
    for (auto val: ans) {
        cout << val << " ";
    }cout << endl;
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
