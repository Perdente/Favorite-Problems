//https://www.codechef.com/problems/ODTPIC
// https://www.codechef.com/viewsolution/54947846
/*
a = { 3,3,2,4,3,1,3 }
b = { 7,3,5,2,2,4 }
(l1,r1)=(1,5) and (l2,r2)=(2,5) then the segments are 
  {3,3,2,4,3}, {3,5,2,2}
=> {3,2,4}     {3,5} 
=> {2,4,5} // only the odd frequency elements stay
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 4e3+4, mx = 1e5+5;

void Malena(){
	int n, m, q, x; cin >> n >> m >> q;
	bitset <N> a_pref[n+1],b_pref[m+1];
	bitset <N> a, b; // these bitsets stores the fliped bits
	for (int i = 1; i <= n; ++i){
		cin >> x;
		a[x] = ~a[x]; // each time we flip the bits if xth bit=1 then x is odd in the whole set, or vice versa
		a_pref[i] = a; // each fliped sets stored in pref bitsets
	}
	for (int i = 1; i <= m; ++i){
		cin >> x;
		b[x] = ~b[x];
		b_pref[i] = b;
	}
	while (q--) {
		int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
		cout << ((a_pref[r1] ^ a_pref[l1-1]) ^ (b_pref[r2] ^ b_pref[l2-1])).count() << endl; // count() method gives the total set bits in bitset
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
