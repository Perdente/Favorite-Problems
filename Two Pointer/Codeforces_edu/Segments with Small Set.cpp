//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
int cnt[N];
int k,ans;
void add(int x){
    cnt[x]++;
    if(cnt[x]==1)ans++;
}
void remove(int x){
    cnt[x]--;
    if(cnt[x]==0)ans--;
}
bool good(){
    return ans<=k;
}
signed main()
{
	int n;cin>>n>>k;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	int l=0,res=0;
	for(int r=0;r<n;++r)
	{
	    add(v[r]);
	    while(!good()){
	        remove(v[l]);
	        l++;
	    }
	    res+=r-l+1;
	}
	cout<<res<<"\n";
	return 0;
}

