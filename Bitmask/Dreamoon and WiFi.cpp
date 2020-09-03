/*https://codeforces.com/problemset/problem/476/B*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,s1;cin>>s>>s1;
    cout<<fixed<<setprecision(20);
    int cnt=0,cnt1=0,q=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='+')cnt++;
        else cnt--;
    }
    for(int i=0;i<s1.size();++i)
    {
        if(s1[i]=='+')cnt1++;
        else if(s1[i]=='-')cnt1--;
        else q++;
    }
    int tot=abs(cnt-cnt1);
    double ans=0;
    for(int i=0;i<(1<<q);++i)
    {
        int temp=0;
        for(int j=0;j<q;++j)
        {
            if(i&(1<<j))temp++;
            else temp--;
        }
        if(temp==tot)ans++;
    }
    ans/= 1<<q;
    cout<<ans<<endl;
	return 0;
}
