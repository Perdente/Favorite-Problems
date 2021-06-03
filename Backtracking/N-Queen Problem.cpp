//https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1#
class Solution{
public:
    vector<vector<int>>result;
    int row[10];
    
    bool placeable(int r,int c){
        for(int i=0;i<c;++i){
            if(row[i]==r or abs(row[i]-r)==abs(i-c) )return false;
        }
        return true;
    }
    
    void backtrack(int c,int n){
        if(n==2 or n==3)return ;
        if(c==n){
            vector<int>v;
            for(int i=0;i<n;++i){
                v.push_back(row[i]+1);
            }
            result.push_back(v);
        }
        for(int i=0;i<n;++i){
            if(placeable(i,c)){
                row[c]=i;
                backtrack(c+1,n);
            }
        }
    }
    
    
    vector<vector<int>> nQueen(int n) {
        // code here
        result.clear();
        backtrack(0,n);
        return result;
    }
};
