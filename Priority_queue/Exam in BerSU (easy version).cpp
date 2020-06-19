/*https://codeforces.com/problemset/problem/1185/C1*/
/*
Problem:if prefix sum is greater than k then erase elements in the array to fit the sum within k.
priority_queue implementation:
1.Implement prefix sum.
2.Here only the bigger elements might get erased.So we use max_heap(priority_queue) to store all elements in decreasing order.
3.If prefix sum is greater then k then we traverse the queue and erase the top elements until it meets the condition.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;cin>>n>>k;
    vector<int>v(n),presum(n,0),ans;
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    presum[0]=v[0];
    for(int i=1;i<n;++i)
    {
        presum[i]=presum[i-1]+v[i];
    }
    priority_queue<int>pq;
    int cnt;
    for(int i=0;i<n;++i)
    {
        cnt=0;
        if(presum[i]>k)
        {
            int d=presum[i];
            priority_queue<int>temp=pq;
            while(!temp.empty())
            {
                if(d<=k)break;
                int f=temp.top();
                d-=f;
                temp.pop();
                cnt++;
            }
        }
        pq.push(v[i]);
        ans.push_back(cnt);
    }
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
}
