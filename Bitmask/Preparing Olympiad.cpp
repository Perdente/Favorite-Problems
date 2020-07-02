/*https://codeforces.com/problemset/problem/1097/B
Bitwise implementation:Find the problem set in 2^n - 1 takes
1.Here if(i & (1<<j)){}  returns true if ith bit is SET
2.So if ith bit is SET then calculate the sum and push elements in vector.
3.If sum meets the condition then cnt++.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l,r,x;cin>>n>>l>>r>>x;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<(1<<n);++i)
    {
        if(__builtin_popcount(i)<2)continue;
        vector<int>v;
        int sum=0;
        for(int j=0;j<n;++j)
        {
            if(i & (1<<j))
            {
                v.push_back(a[j]);
                sum+=a[j];
            }
        }
        int p=*max_element(v.begin(),v.end()),q=*min_element(v.begin(),v.end());
        if(sum>=l and sum<=r and p-q>=x)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
