// https://codeforces.com/contest/1061/problem/C
// dp[i]=no of good subseq.until index i
// update the dp table when j divisor to v[i]
// dp[val]+=dp[val-1]

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1e9+7;
const int N=1e6+5;
void Malena(){
	int n;cin>>n;
	vector<int> dp(N);
	dp[0]=1;
	for(int i=0;i<n;++i){
		int x;cin>>x;
		set<int> st;
		for(int j=1;j*j<=x;++j){
			if(x%j==0){
				st.insert(j);
				st.insert(x/j);
			}
		}
		for(auto it=st.rbegin();it!=st.rend();++it){
			int k=*it;
			dp[k]+=dp[k-1];
			dp[k]%=mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=(ans+dp[i])%mod;
	}
	cout<<ans<<endl;
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
