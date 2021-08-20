//https://codeforces.com/problemset/problem/1559/D1
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=3e5+5;

class DSU{
    vector <int> parent, rank, minimum, maximum, total_elements;
    
    public:
        DSU(int n){
            parent.resize(n + 1);
            minimum.resize(n + 1);
            maximum.resize(n + 1);
            total_elements.assign(n + 1, 1);
            rank.assign(n + 1, 0);
            initialize(n);
        }
 
        void initialize(int n){
            for(int i = 1 ; i <= n ; ++i){
                parent[i] = i;
                minimum[i] = i;
                maximum[i] = i;
            }
        }
 
        int find_parent(int element){
            if(parent[element] == element) return element;
            return parent[element] = find_parent(parent[element]);
        }
        
        void union_by_rank(int a, int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if(pa == pb) return;
            if(rank[pa] == rank[pb]) ++rank[pa];
            if(rank[pa] > rank[pb]){
                parent[pb] = pa;
                total_elements[pa] += total_elements[pb];
                minimum[pa] = min(minimum[pa], minimum[pb]);
                maximum[pa] = max(maximum[pa], maximum[pb]);
            } else{
                parent[pa] = pb;
                total_elements[pb] += total_elements[pa];
                minimum[pb] = min(minimum[pa], minimum[pb]);
                maximum[pb] = max(maximum[pa], maximum[pb]);
            }
        }
  
        void union_by_size(int a,int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if (pa != pb) {
                if (total_elements[pa] < total_elements[pb])
                    swap(pa, pb);
                parent[pb] = pa;
                minimum[pa]=min(minimum[pa],minimum[pb]);
                maximum[pa]=max(maximum[pa],maximum[pb]);
                total_elements[pa] += total_elements[pb];
            }
        }

        int getSize(int v){
            return total_elements[find_parent(v)];
        }
 
        int getMin(int v){
            return minimum[find_parent(v)];
        }
 
        int getMax(int v){
            return maximum[find_parent(v)];
        }
};

void Malena(){
  int n;cin>>n;
  DSU dsu(n),dsu1(n);
  int m1,m2;cin>>m1>>m2;
  map<int,int>mp;
  for(int i=0;i<m1;++i){
  	int u,v;cin>>u>>v;
  	dsu.union_by_size(u,v);
  	mp[u]=v;
  }
  for(int i=0;i<m2;++i){
  	int u,v;cin>>u>>v;
  	dsu1.union_by_size(u,v);
  	mp[u]=v;
  }
  vector<pair<int,int>> vp;
  for(int i=1;i<n;++i){
  	for(int j=i+1;j<=n;++j){
  		if(mp[i]==j or mp[j]==i)continue;
  		if(dsu.find_parent(i) != dsu.find_parent(j) and 
  			dsu1.find_parent(i) != dsu1.find_parent(j)){
  			vp.emplace_back(i,j);
  			dsu.union_by_size(i,j);
  			dsu1.union_by_size(i,j);
  		}
  	}
  }
  cout<<vp.size()<<endl;
  for(auto [u,v]:vp){
  	cout<<u<<" "<<v<<endl;
  }
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
  //cin>>t;
  while(t--){
    Malena();
  }
  return 0;
}
