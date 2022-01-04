/*
https://codeforces.com/contest/1621/problem/B
Here, the main observation is that -

always we need to have the pairs with
min {{lowest l, some arbitrary r} + {some arbitrary l, highest r} cost}

one special case is that - if we have the segment with {minL,maxR} ?
Then we take the min of that segment and answer
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
const int oo = 1e18;

void malena(){
    int n; cin >> n;
    pair <int,int> low{oo, oo};
    pair <int,int> high{-oo, -oo};
    pair <int,int> single{-oo, -oo};
    while (n--) {
        int left, right, cost; cin >> left >> right >> cost;
        low = min (low, {left, cost});
        high = max (high, {right, -cost});
        int ans = low.second - high.second;

        single = max (single, {right - left, -cost});
        if (single.first == high.first - low.first) {
            ans = min (ans, -single.second);
        }
        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t=1;
    cin>>t;
    while(t--) malena();
    return 0;
}
