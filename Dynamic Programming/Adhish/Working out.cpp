//https://codeforces.com/contest/429/problem/B

// dp1[i][j]=(1,1) to (i,j)
// dp2[i][j]=(i,j) to (1,m)
// dp3[i][j]=(i,j) to (n,m)
// dp4[i][j]=(n,1) to (i,j)

// two possible case can be either
// 1.(i-1,j)+(i+1,j)+(i,j-1)+(i,j+1)
// 2.(i,j-1)+(i,j+1)+(i-1,j)+(i+1,j)

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e3+5;
int a[N][N],dp1[N][N],dp2[N][N],dp3[N][N],dp4[N][N];
void Malena(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}

	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			dp1[i][j]=a[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
		}
	}

	for(int i=1;i<=n;++i){
		for(int j=m;j>=1;--j){
			dp2[i][j]=a[i][j]+max(dp2[i-1][j],dp2[i][j+1]);
		}
	}

	for(int i=n;i>=1;--i){
		for(int j=m;j>=1;--j){
			dp3[i][j]=a[i][j]+max(dp3[i+1][j],dp3[i][j+1]);
		}
	}

	for(int i=n;i>=1;--i){
		for(int j=1;j<=m;++j){
			dp4[i][j]=a[i][j]+max(dp4[i+1][j],dp4[i][j-1]);
		}
	}

	int ans=0;
	// the meeting point can't be in row(1|n) and col(1|m)
	// so the boundary is from row(2,n-1) and col(2,m-1) 
	for(int i=2;i<=n-1;++i){
		for(int j=2;j<=m-1;++j){
			int op1=dp1[i-1][j]+dp3[i+1][j]+dp4[i][j-1]+dp2[i][j+1];
			int op2=dp1[i][j-1]+dp3[i][j+1]+dp2[i-1][j]+dp4[i+1][j];
			ans=max({ans,op1,op2});
		}
	}
	cout<<ans;
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
