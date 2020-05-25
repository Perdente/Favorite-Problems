/*
merge two arrays according to row .
problem : https://codeforces.com/problemset/problem/625/C
https://stackoverflow.com/questions/61982033/how-i-can-merge-two-2d-arrays-according-to-row-in-c/61993274#61993274
*/


#include <iostream>
using namespace std;

int main() {
	int n,k;cin>>n>>k;
	int p=n-k+1,q=k-1;
	int a[n+1][q+1],b[n+1][p+1],ans[n+1][n+1];
	for(int i=1;i<=n;++i)for(int j=1;j<=q;++j)a[i][j]=0;
	for(int i=1;i<=n;++i)for(int j=1;j<=p;++j)b[i][j]=0;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)ans[i][j]=0;
	
	int x=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=q;++j) a[i][j]=x++;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=p;++j) b[i][j]=x++;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=q;++j) ans[i][j]=a[i][j];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=q+1;j<=n;++j) 
		{
			ans[i][j]=b[i][j-q];
		}
	}
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=1;j<=q;++j)cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=1;j<=p;++j)cout<<b[i][j]<<" ";
//		cout<<endl;
//	}
//	
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(j==k)sum+=ans[i][j];
		}
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
