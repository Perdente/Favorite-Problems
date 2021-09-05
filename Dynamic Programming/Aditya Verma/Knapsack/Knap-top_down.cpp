//https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,W,x,y;cin>>n>>W;
	int wt[n],val[n];
	for(int i=0;i<n;++i){
		cin>>x>>y;
		wt[i]=x,val[i]=y;
	}
	vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
	function<int(int,int)>knapsack=[&](int n,int W)->int{
		if(n==0 or W==0)return 0;
		if(dp[n][W]!=-1)return dp[n][W];
		if(wt[n-1]<=W){
			return dp[n][W]=max(val[n-1]+knapsack(n-1,W-wt[n-1]) , knapsack(n-1,W));
		}else{
			return dp[n][W]=knapsack(n-1,W);
		}
	};
	cout<<knapsack(n,W)<<endl;
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
