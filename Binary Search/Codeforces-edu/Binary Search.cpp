//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
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
	    int l=0,r=n-1;
	    bool flag=false;
	    while(l<=r){
	        int m=(l+r)/2;
	        if(v[m]==x){
	            flag=true;break;
	        }
	        else if(v[m]<x){
	            l=m+1;
	        }
	        else{
	            r=m-1;
	        }
	    }
	    cout<<(flag?"YES":"NO")<<"\n";
	}
	return 0;
}

