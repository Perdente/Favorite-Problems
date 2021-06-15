//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
vector<pair<double,int>>v(n);
        for(int i=0;i<n;++i){
            double x=(arr[i].value*1.0)/(arr[i].weight*1.0);
            v[i]={x,i};
        }
        sort(v.begin(),v.end(),[](const pair<double,int>&a,const pair<double,int>&b){return a.first>b.first;});
        double ans=0.0,sum=0.0;
        for(int i=0;i<n;++i){
            if(sum+arr[v[i].second].weight<W){
                sum+=arr[v[i].second].weight;
                ans+=arr[v[i].second].value;
            }else{
                double x=(W-sum)*1.0;
                ans+=v[i].first*x;
                break;
            }
        }
        return ans;
