#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n,W;cin>>n>>W;
	int wt[n],val[n];
	for(int i=0;i<n;++i){
		cin>>val[i];
	}
	vector<pair<int,int>> it;
	for(int i=0;i<n;++i){
		cin>>wt[i];
		it.emplace_back(wt[i],val[i]);
	}

	auto comp=[&](const pair<int,int> &a,const pair<int,int> &b)->bool{
		double x=((double)a.second/(double)a.first);
		double y=((double)b.second/(double)b.first);
		return x>=y;
	};	
	sort(it.begin(), it.end(),comp);
	
	int cur_wt=0;
	double profit=0.0;
	
	for(int i=0;i<n;++i){
		if(cur_wt+it[i].first<=W){
			cur_wt+=it[i].first;
			profit+=it[i].second;
		}else{
			int rem=W-cur_wt;
			profit+=it[i].second*((double)rem/(double)it[i].first);
			break;
		}
	}
	cout<<profit<<endl;


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
