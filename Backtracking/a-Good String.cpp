//https://codeforces.com/problemset/problem/1385/D
//https://www.youtube.com/watch?v=qKCxmSipFdg&t=227s&ab_channel=CodeNCode
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n;cin>>n;
	char arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	auto cost=[&](int l,int r,char ch)->int{
		int cnt=0;
		for(int i=l;i<=r;++i)
			cnt+=(arr[i]!=ch);
		return cnt;
	};
	function<int(int,int,char)>getmin=[&](int l,int r,char ch)->int{
		if(l==r){
			if(arr[l]==ch)return 0;
			else return 1;
		}
		int m=(l+r)/2;
		return min( (cost(l,m,ch) + getmin(m+1,r,ch+1)) , (getmin(l,m,ch+1) + cost(m+1,r,ch)) );
	};
	cout<<getmin(0,n-1,'a')<<'\n';
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
