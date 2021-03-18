//https://codeforces.com/contest/1326/problem/C
/*A winner is just a loser who tried one more time*/

#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long mx  = 2e5+5;

#define inf 			9e18
#define zero 			-9e18
#define PI   			acos(-1.0)  // 3.1415926535897932
#define Case(J) 		printf("Case %lld: %lld\n",++count,J); ///print case
#define preci           cout<<fixed<<showpoint<<setprecision(20);
#define max3(a,b,c) 		max(a,max(b,c))
#define min3(a,b,c) 		min(a,min(b,c))
#define gcd(a,b) 		__gcd(a,b)
#define lcm(a,b) 		(a*(b/__gcd(a,b) ))
#define MP 			make_pair
#define pb 			push_back
#define rev(v) 			reverse(v.begin(),v.end());
#define srt(v) 			sort(v.begin(),v.end());
#define grtsrt(v) 		sort(v.begin(),v.end(),greater<ll>());
#define full(v)			(v).begin(),(v).end()
#define hellyeah 		exit(0);
#define file 			freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define	debug(a) 		cout<<"*"<<a<<"$"<<endl;
#define	debug2(a,b) 		cout<<"$"<<a<<" "<<b<<"$"<<endl;
#define	debug3(a,b,c) 		cout<<"$"<<a<<" "<<b<<" "<<c<<"$"<<endl;
#define SET(X,D_type)		memset(X, D_type, sizeof(X))
#define groot(A)		{cout<<A<<endl;return;}
#define vins(V)			srt(V)V.resize(unique(V.begin(),V.end())-V.begin());
#define check           	cout<<"Avengers Assemble"<<endl;
#define	lol 			cout<<"\n";
#define meem(X) 		cout<<(X?"Yes":"No")<<endl;
#define joker(V) 		for(auto X:V)cout<<X<<" ";cout<<endl;
#define papiya(Mp) 		for(auto X:Mp)cout<<X.first<<" "<<X.second<<endl;
#define lp(i,a) 		for(ll i=0; i<a;i++)
#define LP(it,S)			for(auto it:S)
#define lp1(i,a,b) 		for(ll i=a; i<=b;i++)
#define rlp(i,b,a) 		for(ll i=(b);i>=(a);--i) 
#define Mat(mat,N,M)		lp(i,N){lp(j,M)cout<<mat[i][j]<<" \n"[j==M-1];}
typedef long long ll;

#define SEIVE
vector<ll>prime;
ll isPrime[mx];
void seive(){	
	for(ll i=2;i<mx;++i)
	{
		if(isPrime[i]==0)
		{
			prime.push_back(i);
			for(ll j=i*i;j<mx;j+=i)
			{
				isPrime[j]=1;
			}
		}
		isPrime[i]^=1;
	}
}
ll ncr(ll n,ll k) {
    double res = 1;
    for (ll i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}

typedef long double ld;
void Loser(){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
long long ceil(ll A,ll B){if(A%B==0)return A/B;else return (A/B)+1ll;}
long long middle(ll a, ll b, ll c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
bool fun(const pair<ll,ll> &a, const pair<ll,ll> &b) {return (a.second - a.first > b.second - b.first); }//sort the vector pair in assending order according to second element
bool ds_first(const pair<ll,ll> &a, const pair<ll,ll> &b){ return (a.first > b.first);}//sort the vector pair in decending order according to first element
bool ds_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return a.second>b.second;}//sort the vector pair in decending order according to second element

typedef deque<ll> Dq;
typedef unordered_set<ll> St;
typedef unordered_map<ll,ll> M;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<pair<ll,ll>> VP;
typedef priority_queue<ll,vector<ll>,greater<ll>> Pq;
string str,str1,str2,str3,str4,str5,str6,str7;
char ch,ch1,ch2,ch3;
bool flag,flag1,flag2;

long long a,b,c,d,e,f,g,h,l,i,j,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z,pos,res,res1,test,cnt,cnt1,cnt2,cnt3,cnt4,sum,sum1,sum2,sum3,ans,ans1,ans2,ans3,ma,ma1,ma2,ma3,mi,mi1,mi2,mi3,temp,temp1,temp2,temp3,temp4;
//long double a,b,c,d,e,f,g,h,l,i,j,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z,cnt,cnt1,cnt2,cnt3,cnt4,sum,sum1,sum2,sum3,ans,ans1,ans2,ans3,ma,ma1,ma2,ma3,mi,mi1,mi2,mi3,temp,temp1,temp2,temp3,temp4;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void SectumSempra()
{
	cin>>n>>k;
	V v;
	sum=0;
	lp(i,n){
		cin>>x;
		if(x>n-k)v.pb(i),sum+=x;
	}
	cnt=1;
	lp(i,v.size()){
		if(i)
			cnt=(cnt%mod*(v[i]-v[i-1])%mod)%mod;
	}
	cout<<sum<<" "<<cnt<<"\n";


	lol
}

int main()
{
	Loser();
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	test=1;
	//cin>>test;
	#ifdef SEIVE
		seive();
	#endif
	while(test--)
	{
		SectumSempra();
	}
	return 0;
}
