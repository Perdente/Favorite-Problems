//https://cses.fi/problemset/task/2190/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Point
{
	int x,y;
};
void Malena(){
	
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	Point p1={x1,y1},q1={x2,y2},p2={x3,y3},q2={x4,y4};
	
	auto Orientation=[&](Point p1,Point p2,Point p3)->int{
		int val=(p2.y-p1.y)*(p3.x-p2.x) - (p2.x-p1.x)*(p3.y-p2.y);
		if(val==0)return 0;
		return (val>0?1:2);
	};

	auto validProjection=[&](int a,int b,int c,int d)->bool{
		if(a>b)swap(a,b);
		if(c>d)swap(c,d);
		return max(a,c)<=min(b,d);
	};
	auto segment_intersect=[&](Point p1,Point q1,Point p2,Point q2)->bool{
		int ori1=Orientation(p1,q1,p2);
		int ori2=Orientation(p1,q1,q2);
		int ori3=Orientation(p2,q2,p1);
		int ori4=Orientation(p2,q2,q1);
		if(ori1 != ori2 and ori3 != ori4)return true;
		
		if(ori1==0 and ori4==0){//4 points are collinear
			if(validProjection(p1.x,q1.x,p2.x,q2.x) and validProjection(p1.y,q1.y,p2.y,q2.y))return true;
		}
		return false;
	};
	cout<<(segment_intersect(p1,q1,p2,q2)?"YES":"NO");
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
