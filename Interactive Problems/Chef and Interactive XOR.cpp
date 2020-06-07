//https://www.youtube.com/watch?v=yoJZj8OuFfk
//https://www.codechef.com/problems/INTXOR
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int arr[n+1];
		memset(arr,0,sizeof(arr));
		int a,b,c,d;
		cout<<"1 1 2 3"<<endl;
		cin>>a;
		cout<<"1 1 2 4"<<endl;
		cin>>b;
		cout<<"1 3 4 5"<<endl;
		cin>>c;
		cout<<"1 3 4 6"<<endl;
		cin>>d;
		int p=a^b;
		arr[5]=c^p;
		arr[6]=d^p;
		int i=5,j=6,k=7;
		int cnt=0;
		int xxor;
		while(k<=n)
		{
			if(cnt%2==0 and cnt>0)
			{
				i+=2;
				j+=2;
			}
			cout<<"1 "<<i<<" "<<j<<" "<<k<<endl;
			cin>>xxor;
			arr[k]=xxor^arr[i]^arr[j]; 
			cnt++;
			k++;
		}
		cout<<"1 "<<n-1<<" "<<n<<" "<<1<<endl;
		cin>>xxor;
		arr[1]=xxor^arr[n]^arr[n-1];
		if(n&1)
		{
			cout<<"1 "<<n-2<<" "<<n<<" "<<2<<endl;
			cin>>xxor;
			arr[2]=xxor^arr[n-2]^arr[n];
		}
		else
		{
			cout<<"1 "<<n-1<<" "<<n<<" "<<2<<endl;
			cin>>xxor;
			arr[2]=xxor^arr[n-1]^arr[n];
		}
		arr[3]=a^arr[1]^arr[2];
		arr[4]=b^arr[1]^arr[2];
		cout<<"2 ";
		for(int i=1;i<=n;++i)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		int end;
		cin>>end;
		if(end==-1)exit(0);
	}
	return 0;
}
