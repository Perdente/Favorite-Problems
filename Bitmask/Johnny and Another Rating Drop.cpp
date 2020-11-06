//https://codeforces.com/problemset/problem/1362/C


#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        
        //https://codeforces.com/blog/entry/78355?#comment-635890
        /*int msb=((int)log2(n)) + 1;
        int ans=0;
        for(int i=0;i<msb;++i)
        {
            ans+=n/(1ll<<i);
        }
        cout<<ans<<endl;
        */
        
        //https://codeforces.com/blog/entry/78355?#comment-636081
        int ans=0;
        while(n)
        {
            ans+=n;
            n/=2;
        }
        cout<<ans<<endl;
        
    }
    
    
	return 0;
}
