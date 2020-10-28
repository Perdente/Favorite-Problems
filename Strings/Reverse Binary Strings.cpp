//https://codeforces.com/contest/1437/problem/B

// Every operation cuts at most 2 pairs 00 or 11
// Cut two such pairs with every operation
// As long as there is a 00-pair, there must be a 11-pair as well, unless all of the string
// but the 00-pair is alternating: 10100101. In this case, we must do one more operation
 
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string str;
        cin>>str;
        int cnt=0,cnt1=0;
        for(int i=0;i<n;++i)
        {
            if(i and str[i]==str[i-1])
            {
                str[i]=='1'?cnt++:cnt1++;
            }
        }
        cout<<max(cnt,cnt1)<<endl;
    }
	return 0;
}

/*//https://codeforces.com/contest/1437/problem/B
//https://codeforces.com/blog/entry/84091?#comment-716005

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string str;
        cin>>str;
        int cnt=0,cnt1=0;
        for(int i=0;i<n;++i)
        {
            if(str[i]==str[(i+1)%n])
            {
                cnt++;
            }
        }
        cout<<cnt/2<<endl;
    }
	return 0;
}
*/
