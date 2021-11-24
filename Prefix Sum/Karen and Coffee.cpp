//https://codeforces.com/contest/816/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
const int N= 2e5+5;

int arr[N],brr[N];
void Malena(){
	int n,k,q;cin>>n>>k>>q;
	memset(arr,0,sizeof(0));
	memset(brr,0,sizeof(0));
	int mi=1e9,ma=0;
	for(int i=0;i<n;++i){
		int x,y;cin>>x>>y;
		arr[x]++;
		arr[y+1]--;
	}
	for(int i=0;i<N;++i){
		arr[i]+=arr[i-1];
	}
	for(int i=0;i<N;++i){
		if(arr[i]>=k)brr[i]=1;
		brr[i]+=brr[i-1];
	}
	while(q--){
		int l,r;cin>>l>>r;
		cout<<brr[r]-brr[l-1]<<endl;
	}
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t=1;
    //cin>>t;y
    while(t--){
        Malena();
    }
    return 0;
}
