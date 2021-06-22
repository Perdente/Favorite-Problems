//https://open.kattis.com/problems/convexhull
//not accepted code
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
double eps=1e-12;
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

int dot(Point p, Point q) { return p.x*q.x + p.y*q.y; } // proportional to cos(x)
double dist(Point p, Point q) { return sqrt(dot(p-q , p-q)); }

void Malena(){
    int n;
    while(cin>>n and n!=0)
    {
        vector<Point>points(n);
        for(auto &p:points){
            p.read();
        }
        sort(points.begin(),points.end());
        vector<Point>convex_hull;
        for(int i=0;i<2;++i){
            const int s=convex_hull.size();
            for(Point &c:points){
                while(convex_hull.size()-s>=2){     
                    Point a=convex_hull.end()[-2];
                    Point b=convex_hull.end()[-1];
                    if(a.triangle(b,c)<=0){//b on the left from a or collinear
                        break;//good segment,don't do anything
                    }
                    convex_hull.pop_back();//remove b
                }
                convex_hull.push_back(c);
            }
            convex_hull.pop_back();//removes last element cause it's repeated
            reverse(points.begin(),points.end());//for the bottom half of convex
        }
        if(n==1)convex_hull=points;
        int k=convex_hull.size();
        if(k==2 and dist(convex_hull[0],convex_hull[1])<eps)convex_hull.erase(convex_hull.begin());
        cout<<convex_hull.size()<<'\n';
        for(Point p:convex_hull){
            cout<<p.x<<" "<<p.y<<'\n';
        }
    }
    cout<<'\n';
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
