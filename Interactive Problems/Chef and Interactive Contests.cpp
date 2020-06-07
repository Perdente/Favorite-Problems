#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	while(n--)
	{
		int x;
		cin>>x;
		cout<<(x<m?"Bad boi":"Good boi")<<endl;
	}
	return 0;
}
