//https://codeforces.com/contest/1610/problem/C
/*
binary search on answer concept ::
We use binary search to find the maximum m that it's possible to invite exactly m people.

Assume we want to invite 'cnt' people. If there are 'cnt' people poorer than ith person,
then there are 'm−cnt−1' people richer than him.
so if (m-x-1<=cnt and cnt<=y) holds then we can increment cnt.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void Malena(){
	int n;cin>>n;
	vector<array<int,2>> v(n);
	for(auto &[x,y]:v)cin>>x>>y;

	auto can_pass=[&](int m){
		int cnt = 0;
		for(auto &[x,y]:v){
			if( m-x-1<=cnt and cnt<=y ) cnt++;
		}
		return cnt>=m;
	};

	int invite = 0, ignore = n+1;
	while(ignore > invite + 1){
		int m = invite + (ignore-invite)/2;
		if(can_pass(m)){
			invite = m;
		}else{
			ignore = m;
		}
	}
	cout<<invite<<endl;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--) Malena();
	return 0;
}
