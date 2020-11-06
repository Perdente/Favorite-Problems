//https://codeforces.com/problemset/problem/1299/A

/*
a|b can be written as: a + b — a&b

subtract both side by b =>
or a|b — b = a + b — a&b — b
or a|b — b = a — a&b
or a|b — b = a&(1-b)
or a|b — b = a&(~ b)

f(f(f(f(a,b),c),d),e) which is equivalent to a&(~b)&(~c)&(~d)&(~e) 

Only the number which you put first is taken as it is and the others have ~ added to them. 
So maintain prefix and suffix of ~ &. Answer would be maximum of pref[i] & ai & suff[i] for all i. 
pref[i] is the value of all the elements from 1 to i-1(using the ~ & operation) and suff[i] is the value of all the elements from i+1 to n(using the same operation).


*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;cin>>n;
    vector<int>v(n),prefix(n+1),suffix(n+1);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    
    /// prefix[i] hold all and operations with ~ x ,x is all elements before i,excluding i
    /// suffix[i] hold all and operations with ~ x ,x is all elements after i ,including i
    prefix[0]=INT_MAX;
    suffix[n]=INT_MAX;
    for(int i=0;i<n;++i)
    {
    	prefix[i+1]=prefix[i]&(~v[i]);
	}
	for(int i=n-1;i>=0;--i)
	{
		suffix[i]=suffix[i+1]&(~v[i]);
	}
	int max_value=-1,position=0;
	for(int i=0;i<n;++i)
	{
		int value=prefix[i]&suffix[i+1]&v[i];
		if(value>max_value)
		{
			position=i;
			max_value=value;
		}
	}
	cout<<v[position]<<" ";
	for(int i=0;i<n;++i)
	{
		if(i!=position)cout<<v[i]<<" ";
	}
	cout<<"\n";
    return 0;
}
