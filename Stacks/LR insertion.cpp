// https://atcoder.jp/contests/abc237/tasks/abc237_d

/*
5
LRRLR
> 1 2 4 5 3 0


*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void malena() {
    int n; cin >> n;
    string s; cin >> s;
    stack <int> a;
    vector<int> v;
    int pos = 0;
    a.push(pos++);
    for (auto ch: s) {
        if (ch == 'L') {
            a.push(pos++);
        } else {
            int top = a.top();
            a.pop();
            v.push_back(top);
            a.push(pos++);
        }
    }
    for (auto val: v) cout << val << " ";
    while (!a.empty()) {
        int top = a.top();
        a.pop();
        cout << top << " ";
    }
    cout << '\n';
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
