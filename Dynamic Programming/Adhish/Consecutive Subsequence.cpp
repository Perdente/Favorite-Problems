//https://codeforces.com/contest/977/problem/F
/*
dp[x] = max len of consecutive seq with last element x.
Base case dp[v[i]]=0 // as map stores initially every elements with 0, no need here.
Reccurence - dp[x] = max(dp[x], dp[x-1]+1) ,x=v[i] for every cons. elmts. 
NB-as 1<=n<=1e9 using arrays would be MLE, so map(unordered) used
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n;cin>>n;
	vector<int> v(n);
	map<int,int> dp;
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	int start,mx_len=0;
	for(int i=0;i<n;++i){
		int x=v[i];
		dp[x]=max(dp[x],1+dp[x-1]);
		if(dp[x]>mx_len){
			mx_len=dp[x];
			start=x-mx_len+1; 
			//the seq would be (x-mx_len+1,x-mx_len+2,......,x-mx_len+mx_len)
			//as it's consecutive.
		}
	}
	cout<<mx_len<<endl;
	for(int i=0;i<n;++i){
		if(v[i]==start){
			cout<<i+1<<" ";
			start++;
		}
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	t=1;
	//cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
