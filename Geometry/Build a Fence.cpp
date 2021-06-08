//https://www.spoj.com/problems/FENCE1/
//https://share.sketchpad.app/21/90b-65f1-db0d8a.png
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int x;
	while(cin>>x and x!=0){
		cout<<fixed<<showpoint<<setprecision(2);
		cout<<((x*x)/acos(-1.0))/2<<'\n';
	}	
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
