//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int cnt=1;
    	int i=1,j=0;
    	while(i<n){
    	    if(arr[i]<=dep[j])cnt++;
    	    else j++;
    	    i++;
    	}
    	return cnt;
    }
