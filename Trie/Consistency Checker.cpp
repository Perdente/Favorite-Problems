#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
int cc=0;
void Malena(){
	int n;cin>>n;
	vector<string>v(n);
	for(string &s:v){
		cin>>s;
	}
	sort(v.begin(),v.end(),[](string s1,string s2){
		return s1.size()<s2.size();
	});
	bool flag=true;
	vector<vector<int>>nxt(1,vector<int>(11));
	vector<bool>is_terminal(1);
	int N=0;

	auto insert=[&](string s){
		int node=0;
		for(char ch:s){
			if(!nxt[node][ch-'0']){
				nxt.push_back(vector<int>(10));
				is_terminal.push_back(false);
				nxt[node][ch-'0']=++N;
			}
			node=nxt[node][ch-'0'];
			if(is_terminal[node])flag=false;
		}
		is_terminal[node]=true;
	};
	for(string &s:v){
		insert(s);
	}
	cout<<"Case "<<++cc<<": ";
	cout<<(flag?"YES":"NO")<<'\n';
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
