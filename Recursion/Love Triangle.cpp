/*https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/can-you-guess-1/*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long BaseConversion(long long n,long long p)
{
	if(n<p)return n;
	return n%p + 10*BaseConversion(n/p,p);
}
 
int main() {
	long long n;
    while(cin>>n)
    {
    	cout<<BaseConversion(n,9)<<endl;
	}
    return 0;
}
