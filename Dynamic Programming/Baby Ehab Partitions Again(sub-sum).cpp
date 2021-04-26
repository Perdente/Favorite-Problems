//subset-sum
/*A winner is just a loser who tried one more time*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9+7;
const int mx  = 2e5+5;

#define inf 			9e18
#define zero 			-9e18
#define PI   			acos(-1.0)  // 3.1415926535897932
#define Case(J) 		printf("Case %lld: %lld\n",++count,J); ///print case
#define preci                   cout<<fixed<<showpoint<<setprecision(20);
#define max3(a,b,c) 		max(a,max(b,c))
#define min3(a,b,c) 		min(a,min(b,c))
#define gcd(a,b) 		__gcd(a,b)//int gcd(int a,int b){return b?gcd(b,a%b):a;}
#define lcm(a,b) 		(a*(b/__gcd(a,b) ))
#define MP 			make_pair
#define pb 			push_back
#define rev(v) 			reverse(v.begin(),v.end());
#define srt(v) 			sort(v.begin(),v.end());
#define grtsrt(v) 		sort(v.begin(),v.end(),greater<ll>());
#define full(v)			(v).begin(),(v).end()
#define hellyeah 		exit(0);
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
#define lp(i,a) 		for(int i=0; i<a;i++)
#define LP(it,S)			for(auto it:S)
#define lp1(i,a,b) 		for(int i=a; i<=b;i++)
#define rlp(i,b,a) 		for(int i=(b);i>=(a);--i) 
#define Mat(mat,N,M)		lp(i,N){lp(j,M)cout<<mat[i][j]<<" \n"[j==M-1];}
#define all(x)              (x).begin(), (x).end()
typedef long long ll;

#define SEIVE
vector<int>prime;
int isPrime[mx];
void seive(){	
	for(int i=2;i<mx;++i)
	{
		if(isPrime[i]==0)
		{
			prime.push_back(i);
			for(int j=i*i;j<mx;j+=i)
			{
				isPrime[j]=1;
			}
		}
		isPrime[i]^=1;
	}
}
int ncr(int n,int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

typedef long double ld;
void Loser(){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
long long ceil(int A,int B){if(A%B==0)return A/B;else return (A/B)+1LL;}
long long middle(int a, int b, int c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
bool as_second(const pair<int,int> &a, const pair<int,int> &b) {return (a.second < b.second); }//sort the vector pair in assending order according to second element
bool ds_first(const pair<int,int> &a, const pair<int,int> &b){ return (a.first > b.first);}//sort the vector pair in decending order according to first element
bool ds_second(const pair<int,int> &a, const pair<int,int> &b) {return a.second>b.second;}//sort the vector pair in decending order according to second element

typedef deque<int> Dq;
typedef unordered_set<int> St;
typedef unordered_map<int,int> M;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<pair<int,int>> VP;
typedef priority_queue<int,vector<int>,greater<int>> Pq;
string str,str1,str2,str3,str4,str5,str6,str7;
char ch,ch1,ch2,ch3;
bool flag,flag1,flag2;

int a,b,c,d,e,f,g,h,l,i,j,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z,pos,res,res1,test,cnt,cnt1,cnt2,cnt3,cnt4,sum,sum1,sum2,sum3,ans,ans1,ans2,ans3,ma,ma1,ma2,ma3,mi,mi1,mi2,mi3,temp,temp1,temp2,temp3,temp4;
//long double a,b,c,d,e,f,g,h,l,i,j,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z,cnt,cnt1,cnt2,cnt3,cnt4,sum,sum1,sum2,sum3,ans,ans1,ans2,ans3,ma,ma1,ma2,ma3,mi,mi1,mi2,mi3,temp,temp1,temp2,temp3,temp4;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
multiset<int>subSetSum;
bool subset_sum(int arr[],int sum,int n)
{
	bool T[n+1][sum+1];
	for(int j=1;j<=sum;++j)
	{
		T[0][j]=false;
	}
	for(int i=0;i<=n;++i)
	{
		T[i][0]=true;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=sum;++j)
		{
			if(arr[i-1]>j)
				T[i][j]=T[i-1][j];
			else
				T[i][j]=T[i-1][j]||T[i-1][j-arr[i-1]];
		}
	}
	int temp=sum;
	for(int i=n;i>0 and temp>0;--i)
	{
		if(T[i][temp]==T[i-1][temp])
		{
			continue;
		}
		else {
			subSetSum.insert(arr[i-1]);
			temp-=arr[i-1];
		}
		
	}

	return T[n][sum];
}

void SectumSempra()
{
	cin>>n;
	int v[n];
	sum=0;
	lp(i,n)cin>>v[i],sum+=v[i];
	if(sum&1)groot(0)
	if(subset_sum(v,sum/2,n)){
		while(true){
			lp(i,n){
				if(v[i]&1 and find(subSetSum.begin(),subSetSum.end(),v[i])!=subSetSum.end()){
					cout<<1<<'\n'<<i+1<<'\n';
					return;
				}
			}
			lp(i,n){
				if(v[i]&1 and find(subSetSum.begin(),subSetSum.end(),v[i])==subSetSum.end()){
					cout<<1<<'\n'<<i+1<<'\n';
					return;
				}
			}
			lp(i,n)v[i]/=2;
		}
	}
	cout<<0<<'\n';
	lol
}

signed main()
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
