//https://codeforces.com/contest/1538/problem/C
/*Fuck ratings give me wrong answers*/

/*
                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'
*/
/*---------------------------------------------------Vector STL/Function----------------------------------------------------------
 * vlli v2(v.begin(),v.begin()+size);
 * vlli v2(v)
 * sort(v.begin().v.end())
 * reverse(v.begin(),v.end())
 * (bool) binary_search(v.begin(),v.end(),key)
 * (iterator) lower_bound(v.begin(),v.end(),key);
 * (iterator) upper_bound(v.bein(),v.end(),key);
 * (iterator) v.lower_bound(key);
 * (iterator) v.upper_bound(key);
 * v.erase(v.begin()+i)
 * v.erase(unique(v.begin(),v.end()),v.end())
 * v.erase(v.begin()+i,v.end()-j)  ||    v.erase(v.begin(),v.begin()+j)
 * v.erase(remove(v.begin(),v.end(),data),v.end())  //erase  all the 'data' from the vector
 * v.erase(v.begin(),v.upper_bound(data)) //all element lower or equal to data are deleated
 * (bool)next_premutation(v.begin(),v.end())
 * (bool)prev_premutation(v.begin(),v.end())
 * v.insert(it,data) || v.insert(i,data)
 * v.insert(it,no_of_times,data) || v.insert(i,no_of_times,data)
 *
 * v.push_back(data),v.pop_back(data),(data) v.front() ,(data) v.back() ,(data) v[index] ,(iterator) v.begin() ,(iterator) v.end()
 * (lli) max_e(v) ,(lli)min_e(v) ,lli fmax_i(v) ,lli lmax_i(v) ,lli fmin_i(v) ,lli lmin_i(v)
 * vector<vector<int>>v(r,vector<int>(c));
 */
 
 /*--------------------------------------------------Vector of pairs----------------------------------------------------------------
  * vector<pair<key_type,data type>> vp
  * vp.push_back(make_pair(key,data))
  *
  * sort by key/first element (then data/second)
  * sort(vp.begin(),vp.end())
  *
  * sort by sec element(only by sec)
  * bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
  * {
  *       return (a.second < b.second);
  * }
  * sort(vp.begin(),vp.end(),sortbysec)
  *
  * (data) vp[i].first ,(data) vp[i].second ,
  */
 
  /*----------------------------------------------String Manupulation -------------------------------------------------------------
   * string str2(str1)
   * string str2(str1.begin(),str1.begin()+length)
   * string s=str.substr(starting_index,length)
   * s.erase(s.begin()+index)
   * s.erase(s.begin()+index,s.end()-index)  ||  s.erase(s.begin()+index(),s.begin()+index)
   * s.erase(unique(s.begin(),s.end()),s.end())  ::adjecent will not be same
   * sort(s.begin(),s.end());
   * reverse(s.begin(),s.end())
   * str.erase(remove(str.begin(),str.end(),'ch'),str.end()); //erase all the 'ch' from string
   * str.insert(it,'ch')  ||  str.insert(i,'ch')
   * str.insert(it,no_of_times,'ch') ||  str.insert(i,no_of_times,'ch')
   * auto c=count(str.begin(),str.end(),'char') //count all char in the given string
   *
   * getline(cin,string_name)
   * stringstream(string_name)>>type1_>>type2_>>type3_.........>>typeN_;
   * stringstream STREAM_name(string_name)
   * STREAM_name>>type1_>>type2_>>type3>>type4_>>type5_;
   * s=to_string(2018)
   */
 
 /* -------------------------------------------------STACK------------------------------------------
  * stack<data_type>s
  * push()              :s.push(data)           :O(1)
  * pop()               :s.pop()                :O(1)
  * top()               :s.top()                :O(1)
  * empty()             :s.empty()              :O(1)
  * size()              :s.size()               :O(1)
  */
 
 /* -------------------------------------------------QUEUE------------------------------------------
  * queue<data_type>q
  * push()               :q.push(data)          :O(1)
  * pop()                :q.pop()               :O(1)
  * front()              :q.front()             :O(1)
  * back()               :q.back()              :O(1)
  * empty()              :q.empty()             :O(1)
  * size()               :q.size()              :O(1)
  */
 
 /*------------------------------------------ priority_queue(default MAX HEAP)-------------------------------
  * priority_queue(data_type>pq
  * push()               :pq.push(data)         :O(log(n))
  * pop()                :pq.pop()              :O(long(n))
  * top()                :pq.top()              :O(1)
  * size()               :pq.size()             :O(1)
  * empty()              :pq.empty()            :O(1)
  */
 
 /*-------------------------------SET:Element in sorted order(increasing) and UNIQUE*****----------------------
 * declaration     :set<lli>s
 * insertion       :s.insert(data)  //insert if it is not present     :O(log(n))
 * size            :s.size()                                          :O(1)
 * find            :auto it=s.find(data) //if it!=s.end -> data found :O(log(n))
 * s.lower_bound() :it=s.lower_bound(data)
 * s.upper_bound() :it=s.upper_bound(data)
 * lower_bound()   :it=lower_bound(s.begin(),s.end(),data)
 * upper_bound()   :it=upper_bound(s.begin(),s.end(),data)
 * erase()         :erase(it)
 * erase()         :s.erase(it1,it2)
 * s.erase()       :s.erase(data)
 * loop            :for(auto it=s.begin();it!=s.end();it++)
 */
 
 /*------------------------------------------MAP:Elemnet r SORTED,unlike set we insert (key and data)--------------------------
 * declaration   :map<key_type,data_type>m
 * insert        :m.insert(make_pair(key,data));                     :O(log(n))
 *               :m.insert(pair<type,type>(key,data))
 * find          :auto it=m.find(key) //if(it!=m.end)it->first=key   :O(log(n))
 * []            :m[key]++      //data=data+1 ,at that key           :O(log(n))
 * size          :m.size()                                           :O(1)
 * m.lower_bound :it=m.lower_bound(key)
 * m.upper_bound :it=m.lower_bound(key)
 * lower_bound   :it=lower_bound(m.begin(),m.end(),key)
 * upper_bound   :it=upper_bound(m.begin(),m.end(),key)
 * erase()       :s.erase(it)
 *               :s.erase(it1,it2)
 *               :s.erase(key)
 * loop          :for(auto it=m.begin();it!=s.end();it++)
 *
 * it->first ,it->second ,
 */
 
 
 /*------------------------------------------Unorderd SET  :Elements in unsorted order(used hasing to store data)------------------------------------
 * declaration   :unordered_set<lli>s
 * insertion     :s.insert(data)                                     :O(1)
 * size          :s.size()                                           :O(1)
 * find          :auto it=s.find(data)//if it!=s.end ->data found    :O(1)     ||  worst case O(n)
 * loop          :for(auto it=s.begin();it!=s.end();it++)
 */
 
 /*-------------------------------------Unordered MAP:Element r UNSORTED,unlike unordered set we insert (key and data)||-----------------------------
 * declaration   :unorderd_map<key_type,data_type> m
 * insert        :insert(make_pair(key,data))                        :O(1)
 * find          :auto it=m.find(key) //if (it!=m.end)it->first=key  :O(1)
 * []            :m[key]++      //data=data+1 ,at that key           :O(1)
 * size          :m.size()                                           :O(1)
 * loop          :for(auto it=s.begin();it!=s.end();it++)
 */
 
 /*--------------------------------------- mutiset:similar to set but have duplicate element--------------------------------------------------------
  * multiset<data_type>ms
  * insert()               :ms.insert(data)         :O(log(n))
  * find()                 :auto it=ms.find(data)   :O(long(n))
  * size()                 :ms.size()               :O(1)
  */
 
  /* --------------------------multimap:similar to MAP but can have duplicate keys  :search O(logn):insert O(logn):delete O(logn)------------------
   * mulimap<key_type,data_type>mm
   * mm.insert(pair<key_type,data_type>(key,data))        :O(long(n))
   * multimap<key_type,data_type> mm2(mm.begin(),mm.end())
   * find()                :it=mm.find(key)  //first it   :O(long(n))
   * mm.lower_bound(key)->second //data      mm.lower_bound(key)=it  1st elemet having the key  or mm.end()
   * mm.upper_bound(key)->second //data      mm.upper_bound(key)=it  1st element just after the key or mm.end()
   * mm.erase(key)         :erase all element of the key value
   * mm.erase(mm.begin(),mm.find(key))    :remove all having(key) less than the given key
   * mm.size()                                             :O(1)
   * for(auto it=mm.begin();it!=mm.end;it++)     :traversal
   */
 
   /*-------------------------------------------------------------LIST(doubly linked list)--------------------------------------------------------------------------------
    * advantage: quick insertion and deletion ,bigger size
    * disadvantage: slow traversal
    * list<data_tupe>l
    * (data) l.front()
    * (data) l.back()
    * l.push_front(data)
    * l.push_back(data)
    * l.pop_front()
    * l.pop_back()
    * (it) l.begin()
    * (it) l.end()
    * (bool) l.empty()
    *
    *
    *
    *
    */
/*8___8______________________8___8____
___*8___8*____________________*8___8*___
__*88___88*__________________*88___88*__
_*888___888*________________*888___888*_
_*8888_8888*________________*8888_8888*_
__*8888888*__________________*8888888*__
___*88888*____________________*88888*___
____*888*_________7**7_________*888*____
____*88*_________*8888*_________*88*____
_____*88*_______88888888_______*88*_____
_8_____*8*_____8888888888_____*8*_____8_
__8*_____*8*__8_88888888_8__*8*_____*8__
____88*________8888888888________*88____
_8_____*8888*_8_88888888_8_*8888*_____8_
___88__________8888888888__________88___
_8_____*8888*_8_88888888_8_*8888*_____8_
___*8*_________8888888888_________*8*___
__8____*888*__8_88888888_8__*888*____8__
____88_________8888888888_________88____
_______*888*__8_88888888_8__*888*_______
_______________8888888888_______________
_______________*88888888*_______________
________________*888888*________________
_________________*8888*_________________
___________________*888_________________
_____________________*88________________
_____________6_________*88______________
___________*8____________*88____________
__________*88______________*8*__________
_________*8888*______________*8*________
_________*888*________________*8*_______
__________*88*________________*8*_______
___________*8*_______________*8*________
____________*8*_____________*8*_________
______________*8*_________*8*___________
_________________*<88888>*_____________*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define endl "\n"
const int MOD = 1e9+7;
const int mx  = 2e5+5;
typedef long long ll; 

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// using namespace std;
// #define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

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

#define inf       9e18
#define zero      -9e18
#define PI        acos(-1.0)  // 3.1415926535897932
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b)    (a*(b/__gcd(a,b) ))
#define MP        make_pair
#define pb        push_back
#define rev(v)      reverse(v.begin(),v.end());
#define srt(v)      sort(v.begin(),v.end());
#define grtsrt(v)     sort(v.begin(),v.end(),greater<ll>());
#define full(v)     (v).begin(),(v).end()
#define hellyeah    exit(0);
#define vmax(V)     *max_element(V.begin(),V.end());
#define vmin(V)     *min_element(V.begin(),V.end());
#define Mem(X,D_type) memset(X, D_type, sizeof(X))
#define groot(A)    {cout<<A<<endl;return;}
#define vins(V)     srt(V)V.resize(unique(V.begin(),V.end())-V.begin());
#define check           cout<<"Avengers Assemble"<<endl;
#define lol       cout<<endl;
#define meem(X)     cout<<(X?"Yes":"No")<<endl;
#define joker(V)    for(auto X:V)cout<<X<<" ";cout<<endl;
#define papiya(Mp)    for(auto X:Mp)cout<<X.first<<" "<<X.second<<endl;
#define lp(i,a)     for(int i=0; i<a;i++)
#define LP(it,S)      for(auto it:S)
#define lp1(i,a,b)    for(int i=(a);i<=(b);++i)
#define rlp(i,b,a)    for(int i=(b);i>=(a);--i) 
#define Mat(mat,N,M)  lp(i,N){lp(j,M)cout<<mat[i][j]<<" \n"[j==M-1];}
#define debug(a)    cout<<"*"<<a<<"$"<<endl;
#define debug2(a,b)     cout<<"$"<<a<<" "<<b<<"$"<<endl;
#define debug3(a,b,c)     cout<<"$"<<a<<" "<<b<<" "<<c<<"$"<<endl;
#define fr(i,a,b)       for(int i = (a); i <= (b); i++)
#define pb              push_back
#define f               first
#define se              second
#define pii             pair < int , int >
#define mp              make_pair
#define LOGMAX          17
#define FIND(N,pos)     ((N) & (1 << (pos)))
#define sf(h)           scanf("%d",&h)
#define sff(h,b)        scanf("%d%d",&h,&b)
#define sfff(h,b,c)     scanf("%d%d%d",&h,&b,&c)
#define TCASE(test)     for(int z = 1;z <= test;z++)
#define PRINT           printf("Case %d:\n",z)
#define en              "\n"
#define lwb             lower_bound
#define upb             upper_bound
#define IOS             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define rep(i,l,r)      for(int i = (l);i <= (r);i++)
#define all(x)          (x).begin(), (x).end()
#define SZ(x) x.size()

int mod(int M){return (M % MOD + MOD)%MOD;}
int ceil(int A,int B){if(A%B==0)return A/B;else return (A/B)+1ll;}
int middle(int a, int b, int c) { if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
bool as_second(const pair<int,int> &a, const pair<int,int> &b) {return (a.second < b.second); }
bool ds_first(const pair<int,int> &a, const pair<int,int> &b){ return (a.first > b.first);}
bool ds_second(const pair<int,int> &a, const pair<int,int> &b) {return a.second>b.second;}
 
int ncr(int n,int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef pair < pii , pii > ppiipii;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;
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

void Incurcious()
{ 
  cin>>n>>l>>r;
  V v(n);
  lp(i,n){
  	cin>>v[i];
  }
  srt(v)
  sum=0;
  lp(i,n){
  	x=upper_bound(v.begin()+i+1,v.end(),r-v[i])-v.begin();
  	y=lower_bound(v.begin()+i+1,v.end(),l-v[i])-v.begin();
  	if(x<y)continue;
  	sum+=x-y;
  }
  cout<<sum;
  lp(i,1000)
  {
    //check
  }
  lol
}

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        #ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
         freopen("output.txt","w",stdout);
        #endif
  
  #ifdef SEIVE
    seive();
  #endif
        test=1;
  cin>>test;
  while(test--)
  {
    Incurcious();
  }
  return 0;
}
