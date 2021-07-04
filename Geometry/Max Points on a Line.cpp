//https://leetcode.com/problems/max-points-on-a-line/
//https://www.youtube.com/watch?v=Y8_WxLKYQ6Q&ab_channel=codeExplainer
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        if(n<=2)return n;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int cnt=2;
                for(int k=0;k<n;++k){
                    if(i!=k and j!=k){
                        int temp=(points[j][1]-points[i][1])*(points[k][0]-points[j][0]);
                        int temp1=(points[k][1]-points[j][1])*(points[j][0]-points[i][0]);
                        if(temp==temp1)cnt++;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
