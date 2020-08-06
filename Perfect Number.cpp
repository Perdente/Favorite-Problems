/*
https://codeforces.com/problemset/problem/919/B
Problem:Get the nth smallest integer whose sum of the digits equals p(here 10)
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,sum=0,temp,a;cin>>n;
    while(n)
    {
      sum++;
      temp=0;
      a=sum;
      while(a)
      {
        temp+=a%10;
        a/=10;
      }
      if(temp==10)n--;
    }
	  cout<<sum<<endl;
    return 0;
}
