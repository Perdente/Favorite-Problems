//https://www.hackerrank.com/contests/my-contest-1597865524/challenges/221b-baker-street-london
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const long long mx  = 1e5+5;

#define inf             INT_MAX
#define zero             INT_MIN
#define PI               acos(-1.0)  // 3.1415926535897932
#define Case(J)         printf("Case %lld: %lld\n",++count,J); ///print case
#define Loser             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define GCD(a,b)         __gcd(a,b)
#define LCM(a,b)         (a*(b/__gcd(a,b) ))
#define MP                 make_pair
#define pb                 push_back
#define ppb             pop_back
#define pf                 push_front
#define ppf             pop_front
#define rev(v)             reverse(v.begin(),v.end());
#define srt(v)             sort(v.begin(),v.end());
#define grtsrt(v)         sort(v.begin(),v.end(),greater<ll>());
#define hellyeah         exit(0);
#define file             freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define vmax(v)         *max_element(v.begin(),v.end());
#define vmin(v)         *min_element(v.begin(),v.end());
#define    debug(a)         cout<<"*"<<a<<"$"<<endl;
#define    debug2(a,b)     cout<<"$"<<a<<" "<<b<<"$"<<endl;
#define    debug3(a,b,c)     cout<<"$"<<a<<" "<<b<<" "<<c<<"$"<<endl;
#define SET(X,D_type)    memset(X, D_type, sizeof(X))
#define SET2d(x,m,n)     memset(x, 0, sizeof(x[0][0]) * m * n)
#define groot(A)        return cout<<A<<endl,0
#define vins(V)            srt(V)V.resize(unique(V.begin(),V.end())-V.begin());
#define check           cout<<"Avenger's Assemble"<<endl;
#define    lol             cout<<'\n';
#define meem(x)         cout<<(x?"YES":"NO")<<endl;
#define joker(v)         for(auto x:v)cout<<x<<" ";cout<<endl;
#define papiya(mp)         for(auto x:mp)cout<<x.first<<" "<<x.second<<endl;
#define each(it,S)         for(auto it = S.begin(); it != S.end(); ++it)
#define lp(i,a)         for(ll i=0; i<a;i++)
#define lp1(i,a,b)         for(ll i=(a);i<=(b);++i)
#define rlp(i,b,a)         for(ll i=(b);i>=(a);--i) 
#define Mat(mat,N,M)        lp(i,N){lp(j,M)cout<<mat[i][j]<<" \n"[j==M-1];}
typedef long long ll;
typedef deque<ll,ll> Dq;
typedef set<ll> St;
typedef map<ll,ll> M;
typedef vector<ll> V;
typedef vector<pair<ll,ll>> VP;
ll ceil(ll A,ll B){if(A%B==0)return A/B;else return (A/B)+1ll;}
long long middle(ll a, ll b, ll c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
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
void SECTUMSEMPRA()
{
    cin>>a>>b>>c>>d;
    if(a==d)
    {
        if(a==0 and d==0 and c==0)
        {
            cout<<1<<endl;return;
        }
        else if(a>0 and d>0)
        {
            cout<<1<<endl;return;
        }
        else 
        {
            cout<<0<<endl;return;
        }
    }
    else
    {
        cout<<0<<endl;return;
    }
}

int main()
{
    Loser
    cin>>t;
    while(t--)
    {
        SECTUMSEMPRA();
    }
    return 0;
}
