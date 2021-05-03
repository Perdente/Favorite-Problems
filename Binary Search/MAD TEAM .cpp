//Binary search on answer
//https://atcoder.jp/contests/zone2021/tasks/zone2021_c
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n;cin>>n;
	vector<vector<int>> mat(n,vector<int>(5));
	for(int i=0;i<n;++i){
		for(int j=0;j<5;++j){
			cin>>mat[i][j];
		}
	}

	auto possible = [&](int mi)->bool{
		unordered_set<int>masks;
		for(int i=0;i<n;++i){
			int mask=0;
			for(int j=0;j<5;++j){
				if(mat[i][j]>=mi) mask|=(1<<j);
			}
			masks.insert(mask);
		}
		for(auto first:masks){
			for(auto second:masks){
				for(auto third:masks){
					if((first|second|third)==0b11111)return true;
				}
			}
		}
		return false;
	};

	int l=1,r=1e9+1;
	while(r>l+1){
		int mi=l+(r-l)/2;
		(possible(mi)?l:r)=mi;
	}
	cout<<l<<'\n';
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
