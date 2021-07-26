#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	string s;cin>>s;
	string str="";
	set<string>ans;
	function<void(string,int)>solve=[&](string s,int pos)->void{
		for(int i=pos;i<s.size();++i){
			str.push_back(s[i]);
			solve(s,i+1);
			ans.insert(str);
			str.pop_back();
		}
	};
	solve(s,0);
	for(auto s:ans){
		cout<<s<<'\n';
	}cout<<endl;
	
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
