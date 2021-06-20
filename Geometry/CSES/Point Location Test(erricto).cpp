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
};

void Malena(){
	Point a,b,c;
	a.read();b.read();c.read();
	b-=a;
	c-=a;
	int cross_product=b*c;
	if(cross_product<0)cout<<"RIGHT";
	else if(cross_product>0)cout<<"LEFT";
	else cout<<"TOUCH";
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
	cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
