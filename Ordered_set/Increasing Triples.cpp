//https://atcoder.jp/contests/arc123/tasks/arc123_b
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define int long long int
void Malena(){
	int n,x;cin>>n;
	ordered_multiset os,os1,os2;
	for(int i=0;i<n;++i){
		cin>>x,os.insert(x);
	}
	for(int i=0;i<n;++i){
		cin>>x,os1.insert(x);
	}
	for(int i=0;i<n;++i){
		cin>>x,os2.insert(x);
	}

	auto Upper_Bound1=[&](int element)->int{
		int pos=os1.order_of_key(element+1);
		if(pos==os1.size()) return -1;
		else{
			return *(os1.find_by_order(pos));
		}
	};

	auto Upper_Bound2=[&](int element)->int{
		int pos=os2.order_of_key(element+1);
		if(pos==os2.size()) return -1;
		else{
			return *(os2.find_by_order(pos));
		}
	};

	int cnt=0;
	for(auto ele:os){
		int a=Upper_Bound1(ele);
		int b=Upper_Bound2(a);
		if(a!=-1 and b!=-1){
			cnt++;
			os1.erase(os1.find_by_order(os1.order_of_key(a)));
			os2.erase(os2.find_by_order(os2.order_of_key(b)));
		}
	}
	cout<<cnt<<endl;


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
