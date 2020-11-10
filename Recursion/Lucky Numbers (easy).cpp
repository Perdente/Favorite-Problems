/*https://codeforces.com/contest/96/problem/B*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
const int N=1e5+5;
set<int>st;

void rec(int n,int cnt4,int cnt7)
{
	if(n>1e10)return;
	if(cnt4==cnt7)st.insert(n);
	rec(n*10+4,cnt4+1,cnt7);
	rec(n*10+7,cnt4,cnt7+1);
}

signed main()
{
	rec(0,0,0);
	int x;cin>>x;
	//for(auto i:st)cout<<i<<" ";
	cout<<*st.lower_bound(x)<<endl;
}
