//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define int long long int
const int N=1e5+5;
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    cin.ignore();
    while(t--)
    {
        stack<char>st;
        string s;
        getline(cin,s);
		    bool flag=true;
        for(auto i:s)
        {
            if(i=='(')st.push('(');
            else if(i=='[')st.push('[');
            else 
            {
            	if(st.empty())
            	{
            		flag=false;break;
				}
                if(i==')' and st.top()=='(')st.pop();
                else if(i==']' and st.top()=='[')st.pop();
            }
        }
        cout<<(st.size() or !flag?"No":"Yes")<<endl;
        
    }
	return 0;
}
