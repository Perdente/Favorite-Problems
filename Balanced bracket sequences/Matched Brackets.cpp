//https://www.codechef.com/LRNDSA02/problems/ZCO12001/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    t=1;
    while(t--)
    {
        int n;cin>>n;
        vector<int>v;
        stack<int>st;
        v.push_back(0);
        int ind=0,ma=0,pos=0,len=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            if(x==1)st.push(1);
            else
            {
                st.pop();
                if(st.empty())v.push_back(i);
            }
            if(st.size()>ma)
            {
                ind=i;
                ma=st.size();
            }
        }
        for(int i=1;i<v.size();++i)
        {
            if(v[i]-v[i-1]>len)
            {
                pos=v[i-1]+1;
                len=v[i]-v[i-1];
            }
        }
        cout<<ma<<" "<<ind<<" "<<len<<" "<<pos<<endl;
    }
	return 0;
}
