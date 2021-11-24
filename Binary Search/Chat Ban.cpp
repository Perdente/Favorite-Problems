//https://codeforces.com/contest/1612/problem/C

/*
Statement : You need to find an artimatic progration (1+2+....+k <= x) and
			also( ( k-1 + k-2 + k-3 + ..... + 1 ) <=x )
			say n=3, x=9
			(1 + 2 + 3) + (2 + 1) -> total steps = 5

Approach : Here, for two dif progression we can use two dif binary search.
		if (x <= (n*(n+1))/2) : 1+2+3+....k search k in binary search and calculate k*(k+1)/2
		else :
			tot = (n*(n+1)/2) + ((n-1)*(n-1+1))/2
			rest elements = n - m(the searched element)
			so back_sum= (rest elements*(rest elements-1))/2
			so extra needed tot - back_sum
			search the 'm' for (tot - back_sum)
			ans would be n+m
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void Malena(){
	int n,x;cin>>n>>x;
	int frd_sum = (n*(n+1))/2;
	if(x<=frd_sum){
		int l=0;
		int r=n;
		while(r>l+1){
			int m=l+(r-l)/2;
			if(x <= (m*(m+1))/2){
				r=m;
			}else{
				l=m;
			}
		}
		cout<<r<<endl;
	}else{
		int l=0;
		int r=n-1;
		while(r>l+1){
			int m=l+(r-l)/2;
			int tot=(n*(n+1))/2 + (n*(n-1))/2;
			int temp=n-m;
			int bck_sum= (temp*(temp-1))/2;
			if(x <= tot	- bck_sum){
				r=m;
			}else{
				l=m;
			}
		}
		cout<<n+r<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
