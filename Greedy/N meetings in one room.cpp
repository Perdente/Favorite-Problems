//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;++i){
            v[i]={start[i],end[i]};
        }
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){return (a.second!=b.second?a.second<b.second:a.first<b.first);});
        int cnt=1;
        int i=0,j=1;
        while(j<n){
            if(v[i].second<v[j].first)cnt++,i=j;
            j++;
        }
        return cnt;
    }
