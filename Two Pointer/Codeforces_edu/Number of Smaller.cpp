//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n,m;cin>>n>>m;
	vector<int>v(n),u(m),res(m);
	for(int &i:v)cin>>i;
	for(int &i:u)cin>>i;
	int i=0,j=0;
	while(i<n or j<m)
	{
	    if(j==m or (i<n and v[i]<u[j])){
	        i++;
	    }else{
	        res[j++]=i;
	    }
	}
	for(auto i:res){
	    cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}

