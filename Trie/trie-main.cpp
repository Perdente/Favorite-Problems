//https://www.youtube.com/watch?v=mMz1dNTVnKU&list=PLX4N9vQU5pGapRfdfuB6XHqEUKt9jShyx&index=3&ab_channel=faadcoder
#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Trie{
	struct Trie *child[26];
	bool isend;
	Trie(){
		memset(child,0,sizeof(child));
		isend=false;
	}
};

struct Trie1
{
	bool isend;
	unordered_map<char,Trie1*>mp;
	Trie1(){
		isend=false;
	}
};

struct Trie *root;
struct Trie1 *root1;

void insert(string str){
	struct Trie *cur=root;
	for(char ch:str){
		int idx=ch-'a';
		if(cur->child[idx]==NULL){
			cur->child[idx]=new Trie;
		}
		cur=cur->child[idx];
	}
	cur->isend=true;
}

bool search(string str){
	struct Trie *cur=root;
	for(char ch:str){
		int idx=ch-'a';
		if(cur->child[idx]==NULL){
			return false;
		}
		cur=cur->child[idx];
	}
	return cur->isend;
}

void insert1(string str){
	struct Trie1 *cur=root1;
	for(char ch:str){
		if(!cur->mp.count(ch)){
			cur->mp[ch]=new Trie1;
		}
		cur=cur->mp[ch];
	}
	cur->isend=true;
}

bool search1(string str){
	struct Trie1 *cur=root1;
	for(char ch:str){
		if(!cur->mp.count(ch))
			return false;
		cur=cur->mp[ch];
	}
	return cur->isend;
}

void Malena(){
	
	root=new Trie;
	root1=new Trie1;
	int n;cin>>n;
	while(n--){
		string s;cin>>s;
		insert1(s);
	}
	int q;cin>>q;
	while(q--){
		string str;cin>>str;
		if(search1(str)){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
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

/*

4
abc
bcdd
afag
abba
4
abcd
abc
a
ab

No
Yes
No
No

*/
