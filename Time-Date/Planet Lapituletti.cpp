//https://codeforces.com/problemset/problem/1493/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){

	int H,M;cin>>H>>M;
	int a,b;char ch;
	cin>>a>>ch>>b;
	//assert(ch==':');
	auto process=[&](int x)->int{
		if(set<int>({0,1,8}).count(x)) return x;
		if(set<int>({2,5}).count(x)) return x^2^5;
		return 1e6;
	};

	auto check=[&](int x)->int{
		return process(x%10)*10+process(x/10);
	};

	while(true){
		int m=check(a);
		int h=check(b);
		if(h<H and m<M)break;
		if(++b==M){
			if(++a==H)a=0;
			b=0;
		}
	}
	printf("%02d:%02d\n", a, b);
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
