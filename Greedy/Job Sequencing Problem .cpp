//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr,arr+n,comp);
       int possi[n]={0};
       int cnt=0,sum=0;
       for(int i=0;i<n;++i){
           int j=min(n,arr[i].dead-1);
           while(j and possi[j]==-1)j--;
           if(possi[j]!=-1){
               cnt++,sum+=arr[i].profit,possi[j]=-1;
           }
       }
       return {cnt,sum};
    }
