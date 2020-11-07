/*https://codeforces.com/problemset/problem/1095/C*/
/*
.Here if no of set bits are greater than k then the no of summands are greater than k so ans is no.
.Priority queue stores all the value in non increasing order so we put all the powers of 2 in pq.
.Again every power of 2 can be written as 2* (power of 2)/2 so we can increase the value of count.  
.If cur/2<=0 then it's invalid so ans is no.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;cin>>n>>k;
    if(__builtin_popcount(n)>k)cout<<"NO"<<endl;
    else
    {
        priority_queue<int>pq;
        for(int i=0;i<30;++i)
        {
            if(n&(1<<i))pq.push((1<<i));
        }
        while(pq.size()<k)
        {
            int cur=pq.top();
            if(cur/2<=0)
            {
                cout<<"NO"<<endl;exit(0);
            }
            pq.push(cur/2);
            pq.push(cur/2);
            pq.pop();
        }
        cout<<"YES"<<endl;
        while(pq.size())
        {
            cout<<pq.top()<<" ";
            pq.pop();
        }
    }
	return 0;
}
