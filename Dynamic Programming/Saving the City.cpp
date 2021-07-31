//https://codeforces.com/contest/1443/problem/B
// dp[i] -> min cost to place mines from jth index

// if str[i]=='1'
// 	if j>=0
// 		dp[i] = last cost till j + min { activating one mine , (size of gaps between mines) * placing one mine}  
// 	else
// 		dp[i] = activating one mine // as there is no gaps

// print dp[j] // min cost until j 

// Input:
// 5 1
// 01101110
// Output:
// 6

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int a,b;cin>>a>>b;
	string str;cin>>str;
	int n=str.size();
	vector<int>dp(n,1e9);
	int j=-1;//last pos of '1' from i
	for(int i=0;i<n;++i){
		if(str[i]=='1'){
			if(j>=0){
				dp[i]=min(dp[j]+a,dp[j]+(i-j-1)*b);
			}else{
				dp[i]=a;
			}
			j=i;
		}
	}
	cout<<(j==-1?0:dp[j])<<'\n';
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
	cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
