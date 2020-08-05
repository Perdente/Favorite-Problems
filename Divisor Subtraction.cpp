#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const long long mx  = 1e5+5;

#define inf 			    INT_MAX
#define setbit(A)           __builtin_popcount(A)
#define PI   			    acos(-1.0)  // 3.1415926535897932
#define Case(J) 		    printf("Case %lld: %lld\n",++count,J); ///print case
#define Loser 			    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max3(a,b,c) 	    max(a,max(b,c))
#define min3(a,b,c) 	    min(a,min(b,c))
#define GCD(a,b) 		    __gcd(a,b)
#define LCM(a,b) 		    (a*(b/__gcd(a,b) ))
#define MP 				    make_pair
#define pb 				    push_back
#define ppb 			    pop_back
#define pf 				    push_front
#define ppf 			    pop_front
#define rev(v) 			    reverse(v.begin(),v.end());
#define srt(v) 			    sort(v.begin(),v.end());
#define grtsrt(v) 		    sort(v.begin(),v.end(),greater<ll>());
#define hellyeah 		    exit(0);
#define file 			    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define vmax(v) 		    *max_element(v.begin(),v.end());
#define vmin(v) 		    *min_element(v.begin(),v.end());
#define	debug(a) 		    cout<<"*"<<a<<"$"<<endl;
#define	debug2(a,b) 	    cout<<"$"<<a<<" "<<b<<"$"<<endl;
#define	debug3(a,b,c) 	    cout<<"$"<<a<<" "<<b<<" "<<c<<"$"<<endl;
#define SET(X,D_type)	    memset(X, D_type, sizeof(X))
#define groot(A)		    return cout<<A<<endl,0
#define vins(V)			    srt(V)V.resize(unique(V.begin(),V.end())-V.begin());
#define check               cout<<"Avenger's Assemble"<<endl;
#define	lol 			    cout<<'\n';
#define meem(X) 		    cout<<(X?"YES":"NO")<<endl;
#define joker(V) 		    for(auto X:V)cout<<X<<" ";cout<<endl;
#define papiya(Mp) 		    for(auto X:Mp)cout<<X.first<<" "<<X.second<<endl;
#define each(IT,S) 		    for(auto IT = S.begin(); IT != S.end(); ++IT)cout<<(*IT)<<endl;
#define lp(i,A) 		    for(ll i=0; i<A;i++)
#define lp1(i,A,B) 		    for(ll i=(A);i<=(B);++i)
#define rlp(i,B,A) 		    for(ll i=(B);i>=(A);--i)
#define Mat(mat,N,M)		lp(i,N){lp(j,M)cout<<mat[i][j]<<" \n"[j==M-1];}
/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/
typedef long long ll;
typedef vector<ll> V;
typedef vector<pair<ll,ll>> VP;
ll ceil(ll A,ll B){if(A%B==0)return A/B;else return (A/B)+1ll;}
ll middle(ll A, ll B, ll C) { if ((A <= B && B <= C) || (C <= B && B <= A)) return B;else if ((B <= A && A <= C) || (C <= A && A <= B))return A;else return C; }
bool ispalindrom(string s) {transform(s.begin(),s.end(),s.begin(),::tolower);return (s[0]==s[s.size()-1]?1:0);}
//sort(v.begin(),v.end(),as_second);
bool as_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return (a.second < b.second); }//sort the vector pair in assending order according to second element
bool ds_first(const pair<ll,ll> &a, const pair<ll,ll> &b){ return (a.first > b.first);}//sort the vector pair in decending order according to first element
bool ds_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return a.second>b.second;}//sort the vector pair in decending order according to second element
/*max element in map*/
template<typename KeyType, typename ValueType> //auto max=get_max(x);
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {//std::cout << max.first << "=>" << max.second << std::endl;  //set->max:m=*a.rbegin();min:mi=*a.begin();
  using pairtype=std::pair<KeyType,ValueType>;
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;//min->p1.second>p2.second
  });
}
template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs) {
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin());
}
string str,str1,str2,str3,str4,str5,str6,str7;
char ch,ch1,ch2,ch3;
bool flag=true,flag1=true,flag2=true;
long long a,b,c,d,e,f,g,h,l,i,j,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z,cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,sum=0,sum1=0,sum2=0,ans=0,ans1=0,ans2=0,sum3=0,ma=0,ma1=0,mi=inf,mi1=inf,temp=0,temp1=0,temp2=0;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
	Loser
	cin>>n;
	cnt=0;
	for(ll i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			n-=i;
			cnt++;
		}
		if(n%2==0)
		{
			cnt+=n/2;
			break;
		}
	}
	cout<<(cnt==0?1:cnt)<<endl;
	return 0;
}
