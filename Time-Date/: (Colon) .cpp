/*https://atcoder.jp/contests/abc168/tasks/abc168_c*/
/*https://www.youtube.com/watch?v=MMIsHmZyAxk&feature=youtu.be&ab_channel=Algorythm*/
/*
cosaine law-c^2=a^2+b^2-2*a*b*cos(theta).

As the clock is 360` so for each hour its 360/12= 30`.
and for each minutes its 360/(12*5) its 6`

mdeg/=12 for the hour hand in between minutes space.

The answer lies between hdeg and mdeg

cosaine gives ans is in radian but we need in degree so 1 rad= pi/180

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
#define pi acos(-1.0)
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long double a,b,h,m;
    cin>>a>>b>>h>>m;
    long double hdeg=h*30,mdeg=m*6;
    hdeg+=mdeg/12;
    long double deg=abs(hdeg-mdeg);
    long double cosdeg=cos(deg*pi/180);
    long double c=(a*a)+(b*b)-(2*a*b*cosdeg);
    c=sqrt(c);
    cout<<fixed<<showpoint<<setprecision(20);
    cout<<c<<endl;
	return 0;
}
