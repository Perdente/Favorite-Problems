//https://codeforces.com/problemset/problem/86/D
#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N= 1e6+5;

int cnt[N], a[N], ans[N], answer = 0;
int BLOCK;
struct node {
	int L, R, i;
}query[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
	answer+=2*cnt[a[position]]*a[position]+a[position];
	cnt[a[position]]++;
}

void remove(int position) {
	answer-=2*cnt[a[position]]*a[position]-a[position];
	cnt[a[position]]--;
}

signed main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	BLOCK=sqrt(n);

	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<m; i++) {
		cin>>query[i].L>>query[i].R;
		query[i].L--; query[i].R--;
		query[i].i = i;
	}

	sort(query, query + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++) {
		int L = query[i].L, R = query[i].R;
		while(currentL < L) {
			remove(currentL++);
		}
		while(currentL > L) {
			add(currentL-1);currentL--;
		}
		while(currentR <= R) {
			add(currentR++);
		}
		while(currentR > R+1) {
			remove(currentR-1);currentR--;
		}
		ans[query[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		cout<<ans[i]<<"\n";
}
