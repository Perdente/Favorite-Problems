//https://codeforces.com/contest/1566/problem/D1
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 	
using namespace std;
#define P pair<int,int>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set tree<P, null_type,less<P>, rb_tree_tag,tree_order_statistics_node_update> 

#define int long long int

void Malena(){
	int n,m;cin>>n>>m;
	ordered_set os;
	int ans=0;
	for(int i=0;i<m;++i){
		int x;cin>>x;
		// if(i){
		// 	for(auto it:os){
		// 		cout<<it.first<<" "<<it.second<<endl;
		// 	}
		// 	cout<<endl;	
		// }
		ans+=os.order_of_key({x,0});
		os.insert({x,i});
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
	cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
