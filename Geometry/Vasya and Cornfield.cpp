//https://codeforces.com/problemset/problem/1030/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
struct Point
{
  int x,y;
  void read(){cin>>x>>y;}
  Point operator - (const Point& b)const{
    return Point{x-b.x,y-b.y};
  }
  void operator -=(const Point& b){
    x-=b.x;
    y-=b.y;
  }
  int operator *(const Point& b)const{
    return x*b.y-y*b.x;
  }
  int triangle(const Point& b,const Point& c)const{
    return (b-*this)*(c-*this);
  }
  bool operator < (const Point& b)const {
    return make_pair(x,y)<make_pair(b.x,b.y);
  }
};
int dot(Point p,Point q) {return p.x*q.x+p.y*q.y;}
double dist(Point p,Point q){return sqrt(dot(p-q,p-q));}

void Malena(){
  int n,k;cin>>n>>k;
  Point a={0,k},b={k,0},c={n-k,n},d={n,n-k};
  int m;cin>>m;
  while(m--){
  	Point p;
  	p.read();
  	bool flag=true;
  	for(int i=0;i<2;++i){
  		if((a.triangle(c,p)<0 and b.triangle(d,p)<0) or ((a.triangle(c,p)>0 and b.triangle(d,p)>0))){
  			flag=false;
  		}
  		swap(b,c);
  	}
  	cout<<(flag?"Yes":"No")<<endl;
  }
}
 
signed main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int test;
  test=1;
  //cin>>t;
  while(test--){
    Malena();
  }
  return 0;
}
