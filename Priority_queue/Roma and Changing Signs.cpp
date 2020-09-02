/*https://codeforces.com/contest/262/problem/B*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;cin>>n>>m;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        pq.push(x);
    }
    for(int i=0;i<m;++i)
    {
        int p=pq.top();
        pq.pop();
        pq.push(-p);
    }
    int sum=0;
    while(!pq.empty())
    {
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum<<endl;
	return 0;
}
