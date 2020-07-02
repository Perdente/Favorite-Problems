/*https://codeforces.com/problemset/problem/1097/B
Bitwise implementation:Find the combination with 2^n-1 takes.
1.Here if(i & (1<<j)){}  returns true if ith bit is SET
2.So it ith bit is SET then use clockwise otherwise counterclockwise rotation.
3.If it's multiple of 360 return yes.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    for(int i=0;i<(1<<n);++i)//(i<2^n - 1)
    {
        int sum=0;
        for(int j=0;j<n;++j)
        {
            if(i & (1<<j))
            {
                sum+=arr[j];
            }
            else 
            {
                sum-=arr[j];
            }
        }
        if(!(sum%360))return cout<<"YES"<<endl,0;
    }
    cout<<"NO"<<endl;
    return 0;
}
