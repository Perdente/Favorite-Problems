//https://vjudge.net/problem/UVA-10020
/*
Problem : Given several segments of line (int the X axis) with coordinates [Li, Ri]. You are to choose the minimal
amount of them, such they would completely cover the segment [0, M].
Input:
2
1
-1 0
-5 -3
2 5
0 0
1
-1 0
0 1
0 0
Output:
0

1
0 1


Approach:
1. As we need to cover all points from [0, M] we have to sort the pairs in accending order according to first element
so that we can grab as many segments possible and check for futhest point.
2. Here, the key thing is to reach the futhest point from a particular i.
3. If the whole pair array doen't have any segment that can exceed 0 then the answer is 0
4. When we cover the 0 point, then we check how far we can go in our next iteration.
5. When we reach >= M then our loop stops

As, we check each iteration how far we can travel ? in worst case we have to go for M.
So, total complexity is roughly O(M^2)
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void malena() {
    int m; cin >> m;
    int x, y;
    vector<pair<int, int>> segments, ans;
    while (cin >> x >> y and (x != 0 or y != 0)) {
        segments.push_back({x, y});
    }
    int n = segments.size();
    sort(segments.begin(), segments.end(), comp);
    int R = 0, L = 0, newL, i = 0;
    while (R < m) {
        int farthest = 0;
        newL = L;
        for (; i < n; ++i) {
            if (segments[i].first > L) break; // we always check segments till our farthest reach from previous segment
            if (segments[i].second >= newL) {
                newL = segments[i].second;
                farthest = i;
            }
        }
        if (farthest) {
            ans.push_back({segments[farthest].first, segments[farthest].second});
            L = R = newL;
        } else {
            break;
        }
    }
    if (R >= m) {
        cout << (int) ans.size() << '\n';
        for (auto [L, R]: ans) cout << L << " " << R << '\n';
    } else {
        cout << 0 << '\n';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c = 0;
    t = 1;
    cin >> t;
    while(t--) {
        // cout << "Case " << ++c <<": ";
        malena();
        // if (t) cout << '\n';
    }
    return 0;
}
