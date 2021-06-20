//https://cses.fi/problemset/task/2189/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	double x1,x2,x3,y1,y2,y3;cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double ok=(y2-y1)*(x3-x2)-(y3-y2)*(x2-x1);
	if(ok==0)cout<<"TOUCH";
	else if(ok<0)cout<<"LEFT";
	else cout<<"RIGHT";
	cout<<'\n';
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
