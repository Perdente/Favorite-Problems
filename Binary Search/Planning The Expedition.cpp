/*
https://codeforces.com/problemset/problem/1011/B
Problem:Find a number between 1-100 which can be divided among >=n.
Binanry search:(mlogm)
1.Find the total amount of specific food using vector.
2.Run binary search algo between 1-100.
3.If the sum>=n then ans lies within this range.As maximum days needed so left increased mid+1 to the right.
4.Otherwise right decresed mid-1.
*/

#include <bits/stdc++.h>

using namespace std;

int checker(vector<int>&v,int mid,int num)
{
    int sum=0;
    for(int i=1;i<=100;++i)
    {
        sum+=v[i]/mid;
    }
    return sum>=num;
}
int main()
{
    int n,m,k;cin>>n>>m;
    vector<int>v(101);
    for(int i=0;i<m;++i)cin>>k,v[k]++;
    int l=1,r=100,ans=0;
    while(l<=r)
    {
        int mid=(r-l+1)/2 + l;
        if(checker(v,mid,n))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
