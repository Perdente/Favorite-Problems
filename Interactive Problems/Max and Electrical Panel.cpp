//https://www.codechef.com/problems/MAXEP
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,c;cin>>n>>c;
	int cur=1,lg=1,skip=max(1,n/100),zz=n;
	while(1)
	{
		if(cur>=zz)
		{
			if(skip==1)
			{
				cout<<3<<" "<<cur<<endl;
				break;
			}
			skip=max(1,skip/10);
			cur=min(lg+skip,n);
		}
		cout<<1<<" "<<cur<<endl;
		int ind;cin>>ind;
		if(ind==0)
		{
			lg=cur;
			cur+=skip;
		}
		else
		{
			if(skip==1)
			{
				cout<<3<<" "<<cur<<endl;
				break;
			}
			else if(cur==1)
			{
				cout<<3<<" "<<cur<<endl;
				break;
			}
			zz=min(zz,cur);
			cout<<2<<endl;
			skip=max(1,skip/10);
			cur=min(lg+skip,n);
		}
	}
}
