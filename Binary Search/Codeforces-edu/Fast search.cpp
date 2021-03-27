//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n;cin>>n;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	sort(v.begin(),v.end());
	int q;cin>>q;
	while(q--){
	    int x,y;cin>>x>>y;
	    int l=lower_bound(v.begin(),v.end(),x)-v.begin();
	    int r=lower_bound(v.begin(),v.end(),y+1)-v.begin();
	    cout<<r-l<<" ";
	}
	cout<<"\n";
	
	return 0;
}

