//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=3e5+5;
int parent[N],Min[N],Max[N],size[N];

int find_set(int v){
	if(v==parent[v])return v;
	return parent[v]=find_set(parent[v]);
}

bool isSame_set(int a,int b){
	return find_set(a)==find_set(b);
}

//union by size
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
    Min[v]=v;
	Max[v]=v;
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        Min[a]=min(Min[a],Min[b]);
	Max[a]=max(Max[a],Max[b]);
        size[a] += size[b];
    }
}

int getSize(int v){
	return size[find_set(v)];
}

int getMin(int v){
	return Min[find_set(v)];
}

int getMax(int v){
	return Max[find_set(v)];
}

void Malena(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i)make_set(i);
	while(m--){
		string s;cin>>s;
		int x,y;
		if(s=="union"){
			cin>>x>>y;
			union_set(x,y);
		}else{
			cin>>x;
			cout<<getMin(x)<<" "<<getMax(x)<<" "<<getSize(x)<<endl;
		}
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

/*#include<bits/stdc++.h>
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
  int n,m;cin>>n>>m;
  DSU dsu(n);
  while(m--){
    string s;cin>>s;
    int x,y;
    if(s=="union"){
      cin>>x>>y;
      dsu.union_by_size(x,y);
    }else{
      cin>>x;
      cout<<dsu.getMin(x)<<" "<<dsu.getMax(x)<<" "<<dsu.getSize(x)<<endl;
    }
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
*/
