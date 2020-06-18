/*
https://codeforces.com/contest/1238/problem/B
1.Here,every monster is killed if it's in the left corner.So we start our approach from decreasing order.
2.Again,if a position in selected every monster it's left decrease to -r . no of monster doesn't matter .So we use set here.
3.Here every time the last elements in the sets decreased to -r.So we declear temp and if a value is greater than temp then it's not killed yet.so cnt increases
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--)
	{
		int n,r,x;cin>>n>>r;
		set<int,greater<int>>s;//insert the elements in decreasing order
		for(int i=0;i<n;++i)
		{
			cin>>x;
			s.insert(x);
		}
		int temp=0,cnt=0;
		for(auto i:s)
		{
			if(i>temp)
			{
				cnt++;temp+=r;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
