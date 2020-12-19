//https://codeforces.com/problemset/problem/276/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=2e5+5;
int a[N],fenwick[N],fre[N],n,q,ans;

void build(int idx,int val)
{
	while(idx<=n){
		fenwick[idx]+=val;
		idx+=(idx & -idx);
	}
}
int query(int idx)
{
	int sum=0;
	while(idx>0){
		sum+=fenwick[idx];
		idx-=(idx & -idx);
	}
	return sum;
}

signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	while(q--)
	{
		int l,r;cin>>l>>r;
		build(l,1);
		build(r+1,-1);
	}
	for(int i=1;i<=n;++i)
	{
		fre[i]=query(i);
	}
	sort(a+1,a+n+1,greater<int>());
	sort(fre+1,fre+n+1,greater<int>());
	for(int i=1;i<=n;++i)
	{
		ans+=fre[i]*a[i];
	}
	cout<<ans<<endl;
	return 0;
}
