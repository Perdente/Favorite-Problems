//https://codeforces.com/contest/909/problem/C
/*
dp[i]=no of ways till i
base- dp[0]=1 //as always choice is least 1
recurrence-
'f'-> next char has to be always in lev+1
's'-> next char has choice up to [0-l]
ans=dp[mx_lev-1]
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1e9+7;
void Malena(){
	int n;cin>>n;
	int dp[n]={0};
	dp[0]=1;
	int lev=1;
	for(int i=0;i<n;++i){
		char ch;cin>>ch;
		if(ch=='f')lev++;
		else{
			for(int l=1;l<lev;++l){
				dp[l]=(dp[l]+dp[l-1])%mod;
			}
		}
	}
	cout<<dp[lev-1]<<endl;
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
