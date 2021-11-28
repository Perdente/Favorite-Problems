//https://vjudge.net/contest/470780#problem/I
// special type of getline() 
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void Malena(){
	int n,q;cin>>n>>q;
	map<string,int> mp;
	for(int i=0;i<n;++i){
		string s;cin>>s;
		int x;cin>>x;
		mp[s]=x;
	}
	while(q--){
		string str;
		getline(cin,str,'.');// takes input until meets '.'
		stringstream ss(str);
		string word;
		int ans=0;
		while(ss>>word){
			if(mp.count(word)){
				ans+=mp[word];
			}
		}
		cout<<ans<<endl;
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


// Input:
// 7 2
// administer 100000
// spending 200000
// manage 50000
// responsibility 25000
// expertise 100
// skill 50
// money 75000
// the incumbent will administer the spending of kindergarden milk money
// and exercise responsibility for making change he or she will share
// responsibility for the task of managing the money with the assistant
// whose skill and expertise shall ensure the successful spending exercise
// .
// this individual must have the skill to perform a heart transplant and
// expertise in rocket science
// .
// Output:
// 700150
// 150
