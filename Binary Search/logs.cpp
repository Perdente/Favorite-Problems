/*https://atcoder.jp/contests/abc174/tasks/abc174_e*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
int n,m;
vector<double>v(N);
bool check(int p)
{
	int sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=ceil(v[i]/p)-1;
    }
    if(sum<=m) return true;
    return false;
}
int main()
{
    cin>>n>>m;
    double ma=0;
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
        ma=max(ma,v[i]);
    }
    int left=0,right=ma;
    while(right-left>1)
    {
        int mid=(right+left)/2;
        if(check(mid))
        {
            right=mid;
        }
        else
        {
            left=mid;
        }
    }
    cout<<right<<endl;
	return 0;
}
