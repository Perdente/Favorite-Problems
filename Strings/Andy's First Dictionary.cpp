//https://vjudge.net/contest/470780#problem/V
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void Malena(){
	string str;
	set < string > st;
	while ( getline ( cin, str ) and str != ""){
		stringstream ss(str);
		string word;
		while ( ss >> word ){
			string ans = "";
			for (auto ch : word ){
				if ( ('a' <= ch and ch <= 'z') or ('A' <= ch and ch <= 'Z') ){
					ans += tolower(ch);
				}
			}
			st.insert( ans );
		}
	}
	for ( auto i : st ){
		cout << i << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	t=1;
	//cin>>t;
	while(t--) Malena();
	return 0;
}
