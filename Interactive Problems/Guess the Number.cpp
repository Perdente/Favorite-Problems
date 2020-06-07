//https://codeforces.com/blog/entry/45307
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l=1,r=1000000;
	while(l!=r)
	{
		int mid=(l+r+1)/2;
		cout<<mid<<endl;
		string s;
		cin>>s;
		if(s=="<")
		{
			r=mid-1;
		}
		else
		{
			l=mid;
		}
	}
	cout<<"! "<<l<<endl;
	return 0;
}
