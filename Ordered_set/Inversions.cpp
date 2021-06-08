//https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using oset = tree<T,null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
 
	int n; cin>>n;
	oset<int> s;
 
	for(int i = 0, x, y; i<n; i++){
		cin>>x;
		y = s.order_of_key(x);
		s.insert(x);
		cout<<y<<" ";
	}
	cout<<"\n";
	return 0;
}
