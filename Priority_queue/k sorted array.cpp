#include<bits/stdc++.h>
using namespace std;
#define int long long int

void malena() {
    int n, k; cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int a[n];
    priority_queue<int> pq;
    memset(a, 0, sizeof a);
    int j = 0, i = 0;
    while (i < n) {
        pq.push(-arr[i++]);
        if (pq.size() > k) {
            a[j++] = -pq.top();
            pq.pop();
        }
    }
    while (!pq.empty()) a[j++] = -pq.top(), pq.pop();
    for (auto it: a) cout << it << " ";
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

/*
6 2
5 2 1 3 6 4
Output: 1 2 3 4 5 6 


*/
