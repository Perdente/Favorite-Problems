//https://atcoder.jp/contests/abc218/tasks/abc218_e
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};
 
class DSU{
    vector <int> parent, _rank, minimum, maximum, _size;
    public:
        DSU(int n){
            parent.resize(n + 1);
            minimum.resize(n + 1);
            maximum.resize(n + 1);
            _size.assign(n + 1, 1);
            _rank.assign(n + 1, 0);
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
        
        void union_by__rank(int a, int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if(pa == pb) return;
            if(_rank[pa] == _rank[pb]) ++_rank[pa];
            if(_rank[pa] > _rank[pb]){
                parent[pb] = pa;
                _size[pa] += _size[pb];
                minimum[pa] = min(minimum[pa], minimum[pb]);
                maximum[pa] = max(maximum[pa], maximum[pb]);
            } else{
                parent[pa] = pb;
                _size[pb] += _size[pa];
                minimum[pb] = min(minimum[pa], minimum[pb]);
                maximum[pb] = max(maximum[pa], maximum[pb]);
            }
        }
  
        void union_by_size(int a,int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if (pa != pb) {
                if (_size[pa] < _size[pb])
                    swap(pa, pb);
                parent[pb] = pa;
                minimum[pa]=min(minimum[pa],minimum[pb]);
                maximum[pa]=max(maximum[pa],maximum[pb]);
                _size[pa] += _size[pb];
            }
        }
 
        int getSize(int v){
            return _size[find_parent(v)];
        }
 
        int getMin(int v){
            return minimum[find_parent(v)];
        }
 
        int getMax(int v){
            return maximum[find_parent(v)];
        }
};
 
//int cost;
vector<Edge> Kruskal(vector<Edge> edgelist,int n){
	DSU dsu(n);
	vector<Edge> spanningTree;
	sort(edgelist.begin(), edgelist.end());
	for(Edge e: edgelist){
		if(dsu.find_parent(e.u) != dsu.find_parent(e.v)){
			//cost += e.w;
			spanningTree.push_back(e);
			dsu.union_by_size(e.u,e.v);
		}
	}
	return spanningTree;
}
 
 
void Malena(){
	int n,m;cin>>n>>m;
	vector<Edge> edgelist;
	edgelist.resize(m+1);
	int total=0,cost=0;
	for(int i=0;i<m;++i){
		cin>>edgelist[i].u>>edgelist[i].v>>edgelist[i].w;
		total+=max(0LL,edgelist[i].w);
	}
	vector<Edge> spanningTree=Kruskal(edgelist,n);
	for(Edge edge:spanningTree){
		cost+=max(0LL,edge.w);
	}
	cout<<total-cost<<endl;
}
 
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t;
	t=1;
	//cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
