/*https://atcoder.jp/contests/abc182/tasks/abc182_c*/
/*
    We check all the subset for the string upto 2^64.
    if j th bit is set then we check total sum of digits.
    Again,if the sum%3==0 then we just get the maximum of them all
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
const int N=1e5+5;
signed main()
{
    string s;cin>>s;
    int ans=INT_MIN;
    for(int i=1;i<(1<<s.size());++i)
    {
        int cnt=0,len=0;
        for(int j=0;j<s.size();++j)
        {
            if(i&(1<<j))
            {
                cnt+=s[j]-'0';len++;
            }
        }
        if(cnt%3==0 and len>ans)
        {
            ans=len;
        }
    }
    if(ans==INT_MIN)
    {
    	cout<<-1<<endl;return 0;
	}
	cout<<s.size()-ans<<endl;
	return 0;
}
