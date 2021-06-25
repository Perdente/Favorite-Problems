//https://codeforces.com/problemset/problem/851/B
//https://codeforces.com/blog/entry/54317?#comment-384020
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
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
double dot(Point p,Point q) {return p.x*q.x+p.y*q.y;}
double dist(Point p,Point q){return sqrt(dot(p-q,p-q));}
double cross(Point p,Point q){return p.x*q.y-p.y*q.x;}
void Malena(){
  Point a,b,c;
  a.read();b.read();c.read();
  cout<<((a.triangle(b,c) and dist(a,b)==dist(b,c))?"Yes":"No")<<endl;
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
