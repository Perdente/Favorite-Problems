/*https://codeforces.com/problemset/problem/912/B*/
/*
Consider the case for n = 4 , k=3, let's write the numbers from 1 to n in binary:

1 => 001
2 => 010
3 => 011
4 => 100
After observing the sequence above you realise that 3 XOR 4 is maximum, 
because all of the digits in both numbers differ

    011
XOR 100
  = 111 (7) ->(2^msb - 1)
  
To generalise this we need to find the MSB(most significant bit) since we can 
guarantee to find 2 numbers whose digits all differ.
  
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int msb=floor(log2l(n))+1;
    cout<<(k==1?n:(1ll<<msb)-1)<<endl;
}
