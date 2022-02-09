// https://atcoder.jp/contests/abc229/tasks/abc229_c
#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return (a.first > b.first);
}

void malena() {
    int n, capacity; cin >> n >> capacity;
    vector<pair<int, int>> items(n);
    for (auto &[value, weight]: items) {
        cin >> value >> weight;
    }
    sort(items.begin(), items.end(), comp);
    int cur_weight = 0;
    int sum = 0;
    for (auto [value, weight]: items) {
        if (cur_weight + weight <= capacity) {
            sum += value * weight;
            cur_weight += weight;
        } else {
            int remain = capacity - cur_weight;
            cur_weight += capacity;
            sum += value * remain;
            break;
        }
    }
    cout << sum << '\n';
    // for (auto [value, weight]: items) {
    //     cout << value << " " << weight << '\n';
    // }
}

signed main() {
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
