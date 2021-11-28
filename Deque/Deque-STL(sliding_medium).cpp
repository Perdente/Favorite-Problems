//https://vjudge.net/contest/470780#problem/E
//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/#disqus_thread
/*sliding window technique (deque)

Here, we only store the indices of vector (of window k) in decreasing order
so that after erasing the max value we can get the next max value

now we first run a loop til k-1 and store the values in decreasing order
then we can run from k to n and check if the max element is in the window `dq.front()<=i-k`
also if the values are in decreasing order or not? `v[dq.back()]<v[i]`
finally we can push back new index and take the front value from each window

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void Malena(){
	int n,k;cin>>n>>k;
	vector<int> v(n);
	for(auto &it:v){
		cin>>it;
	}
	deque<int> dq;
	for(int i=0;i<k;++i){
		while(!dq.empty() and v[dq.back()]<v[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout<<v[dq.front()]<<" ";
	for(int i=k;i<n;++i){
		while(!dq.empty() and dq.front()<=i-k){
			dq.pop_front();
		}

		while(!dq.empty() and v[dq.back()]<v[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		cout<<v[dq.front()]<<" ";
	}cout<<endl;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--) Malena();
	return 0;
}
