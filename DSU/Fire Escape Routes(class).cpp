//https://www.codechef.com/problems/FIRESC
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1e9+7;

class dsu {
  vector<int> parent,size;
  int cnt;
public:
  dsu(int n) {
    cnt = n;
    parent.resize(n+1);
    iota(parent.begin(), parent.end(), 0);
    size.assign(n+1,1);
  }
  int getCount() {
    return cnt;
  }
  int Find(int v) {
    if(v==parent[v])return v;
    return parent[v]=Find(parent[v]);
  }
  bool isSame(int a,int b){
    return Find(a)==Find(b);
  }
  void Union(int a, int b) {
    a=Find(a);
    b=Find(b);

    if(a!=b){
      if(size[a]<size[b])
        swap(a,b);

      parent[b]=a;
      size[a]+=size[b];
      size[b]=0;
      --cnt;
    }
  }

  int qry() {
    int ans=1;
    int n=parent.size();
    for(int i=0;i<n;++i){
      if(size[i]){
        ans=(ans%mod*size[i]%mod)%mod;
      }
    }
    return ans;
  }
};
void Malena(){
    int n,m;cin>>n>>m;
    dsu d(n);
    while(m--){
      int u,v;cin>>u>>v;
      d.Union(u,v);
    }
    cout<<d.getCount()<<' '<<d.qry()<<'\n';
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
    cin>>t;
    while(t--){
      Malena();
    }
    return 0;
}
