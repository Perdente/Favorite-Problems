/*https://codeforces.com/problemset/problem/611/B*/
/*
.Each number with exactly one zero can be obtained by taking the number without any zeros (e.g. 63(10)?=?111111(2)) 
and subtracting some power of two, e.g. 63(10)-16(10)=
	
	111111(2^x-1)
	-10000(2^y)
----------
	101111

 
.For each 2^x-1 you should iterate over powers of two and try subtracting each of them. 
Now you have candidates for numbers with exactly one zero. For each of them check if it is in the given interval. 

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b;
    cin>>a>>b;
    int cnt=0;
    for(int i=0;i<64;++i)
    {
    	for(int j=0;j<i-1;++j)
    	{
    		int temp=(1ll<<i)-1-(1ll<<j);
    		cnt+=temp>=a and temp<=b;
		  }
	  }
    cout<<cnt<<endl;
    
}
