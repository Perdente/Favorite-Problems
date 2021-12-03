//https://vjudge.net/contest/470780#problem/Q
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void Malena(){
	string str;
	getline ( cin , str );
	stringstream ss ( str );
	string word;
	while( ss >> word ) {
		reverse(word.begin(), word.end());
		cout << word << " ";
	}
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	t=1;
	cin>>t;
	cin.ignore();
	while(t--) Malena();
	return 0;
}
