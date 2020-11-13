/*https://www.spoj.com/problems/MARBLES/*/
/*https://www.youtube.com/watch?v=XxHwEAESa4w&ab_channel=CodeNCode*/
//https://cp-algorithms.com/combinatorics/binomial-coefficients.html
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define int long long int
#define ll long long
int ncr(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--)
	{
		int n,m;cin>>n>>m;
		cout<<ncr(n-1,m-1)<<endl;
	}
	return 0;
}
