//https://leetcode.com/problems/array-nesting/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<bool>visited(n,false);
        int ma=0;
        function<void(int,int)>dfs=[&](int i,int dpt){
            if(visited[i]){
                ma=max(ma,dpt);
                return ;
            }
            visited[i]=true; 
            dfs(nums[i],dpt+1);
        };
        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(i,0);
            }
        }
        return ma;
    }
};
