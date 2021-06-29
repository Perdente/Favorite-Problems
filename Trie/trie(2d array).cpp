#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int n;cin>>n;
	vector<string>v(n);
	for(string &s:v){
		cin>>s;
	}
	sort(v.begin(),v.end(),[](string s1,string s2){
		return s1.size()<s2.size();
	});

	vector<vector<int>>nxt(1,vector<int>(26));
	vector<bool>is_terminal(1);
	int N=0;
	auto insert=[&](string s){
		int node=0;
		for(char ch:s){
			if(!nxt[node][ch-'a']){
				nxt.push_back(vector<int>(26));
				is_terminal.push_back(false);
				nxt[node][ch-'a']=++N;
			}
			node=nxt[node][ch-'a'];
		}
		is_terminal[node]=true;
	};

	auto search=[&](string s)->bool{
		int node=0;
		for(char ch:s){
			if(!nxt[node][ch-'a']) return false;
			node=nxt[node][ch-'a'];
 		}
 		return is_terminal[node];
	};
	for(string &s:v){
		insert(s);
	}
	int q;cin>>q;
	while(q--){
		string s;cin>>s;
		cout<<(search(s)?"YES":"NO")<<'\n';
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
