/*
https://codeforces.com/problemset/problem/1005/C
Bitwise implementation:
1.Map each value so it can later searched in log(n) times.
2.Calculate power of 2 using shift operation (1<<i)
3.If value in map >1 this means the statement is true for all this values.
4.When value is 1 and equals to v[i] this means only the value itself can fulfill the condition which is not acceptable.
Ex- if v[i]==1 so 2^1-1 = 1 so it is not acceptable
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    map<int,int>mp;
    for(int i=0;i<n;++i)cin>>v[i],mp[v[i]]++;
    
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        bool flag=false;
        for(int j=0;j<=30;++j)
        {
            if(mp.find((1<<j)-v[i]) != mp.end())
            {
                if((mp[(1<<j)-v[i]] > 1) or (mp[(1<<j)-v[i]]==1 and ((1<<j)-v[i])!=v[i]))flag=true;
            }
        }
        if(!flag)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
