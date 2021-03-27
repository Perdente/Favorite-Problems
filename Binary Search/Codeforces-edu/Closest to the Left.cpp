//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n,k;cin>>n>>k;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	while(k--){
	    int x;cin>>x;
	    int l=-1;//v[l]<=x
	    int r=n;//v[r]>x
	    while(r>l+1){
	        int m=(l+r)/2;
	        if(v[m]<=x) l=m;
	        else r=m;
	    }
	    cout<<l+1<<"\n";
	}
	
	return 0;
}

