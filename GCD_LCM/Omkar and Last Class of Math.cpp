/*https://codeforces.com/contest/1372/problem/B
https://www.youtube.com/watch?v=a7pHtQ1N6DE
##Find the smallest factor of n##
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        long long n;cin>>n;
        long long f=n;
        for(int i=2;i*i<=n;++i)
        {
            if(n%i==0)
            {
              f=i;break;  
            }
        }
        cout<<n/f<<" "<<n-(n/f)<<endl;
    }
    return 0;
}
