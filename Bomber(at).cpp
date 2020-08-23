/*https://atcoder.jp/contests/abc176/tasks/abc176_e*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int main()
{
	int h,w,m;
	cin>>h>>w>>m;
	map<int,int>row,col;
	set<pair<int,int>>st;
	int r[N*3]={0},c[N*3]={0};
	int Mxrow=0,Mxcol=0;
	for(int i=0;i<m;++i)
	{
	    cin>>r[i]>>c[i];
	    st.insert({r[i],c[i]});
	    row[r[i]]++;
	    col[c[i]]++;
	    Mxrow=max(Mxrow,row[r[i]]);
	    Mxcol=max(Mxcol,col[c[i]]);
	}
	set<int>X,Y;
	for(int i=0;i<m;++i)
	{
	    if(row[r[i]]==Mxrow)X.insert(r[i]);
	    if(col[c[i]]==Mxcol)Y.insert(c[i]);
	}
	int ans=Mxrow+Mxcol-1;
	for(auto i:X)
	{
	    for(auto j:Y)
	    {
	        if(!st.count({i,j}))
	        {
	            cout<<ans+1<<endl;return 0;
	        }
	    }
	}
	cout<<ans<<endl;
	return 0;
}
