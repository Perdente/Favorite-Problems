/*Priority Queue*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	
	cin>>n>>m;
	
	priority_queue <int , vector<int> , greater<int>> Min;
	
	priority_queue <int> Max;
	
	for(int i=0; i<m; i++){
		
		int k;
		
		cin>>k;
		
		Min.push(k);
		
		Max.push(k);
	}
	
	int a,b;
	
	a = b = 0;
	
	for(int i=0; i<n; i++){
		
		int x = Min.top();
		
		Min.pop();
		
		a += x;
		
		x--;
		
		if(x){
			
			Min.push(x);
		}
	}
	
	for(int i=0; i<n; i++){
		
		int x = Max.top();
		
		Max.pop();
		
		b += x;
		
		x--;
		
		if(x){
			
			Max.push(x);
		}
	}
	
	cout<<b<<" "<<a;
	return 0;
}
