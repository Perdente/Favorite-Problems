//https://cses.fi/problemset/task/1730
//http://letuskode.blogspot.com/2014/08/grundy-numbers.html
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long
#define mx 1000005
 
 
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
    	int n,x=0;
    	cin>>n;
    	vector<int>v(n);
    	for(int &i:v)
    	{
    		cin>>i;
    		x^=i;
		}
		cout<<(x?"first":"second")<<endl;
    	
	}
	return 0;
}
