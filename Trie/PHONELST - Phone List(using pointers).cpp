//https://www.spoj.com/problems/PHONELST/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
struct Trie
{
	bool isend;
	unordered_map<char,Trie*>mp;
	Trie(){
		isend=false;
	}
};
 
 
struct Trie *root;
 
bool flag;
void insert(string str){
	struct Trie *cur=root;
	for(char ch:str){
		if(cur->isend)flag=false;
		if(!cur->mp.count(ch)){
			cur->mp[ch]=new Trie;
		}
		cur=cur->mp[ch];
	}
	cur->isend=true;
	for(int i=0;i<10;++i){
		if(cur->mp.count(i+'0')) 
			flag=false;
	}
}
 
void Malena(){
	root=new Trie;
	int n;cin>>n;
	flag=true;
	while(n--){
		string s;cin>>s;
		insert(s);
	}
	cout<<(flag?"YES\n":"NO\n");
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
 
