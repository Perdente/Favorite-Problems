//https://leetcode.com/problems/longest-word-in-dictionary/
class Solution {
    void dfs(int node,string& so_far,string &answer,const vector<vector<int>>& nxt,const vector<bool>& is_terminal){
        
       if(so_far.length()>answer.length()){
           answer=so_far;
       }
      
      for(int c=0;c<26;++c){
          int tmp=nxt[node][c];
          if(tmp!=0 and is_terminal[tmp]){
              so_far+=char('a'+c);
              dfs(tmp ,so_far,answer,nxt,is_terminal);
              so_far.pop_back();
          }
      }
    }
public:
    string longestWord(vector<string>& words) {
        vector<bool>is_terminal(1);//This eventuallly becomes the size of the trie
        vector<vector<int>>nxt(1,vector<int>(26));//This eventuallly becomes the size of the trie * 26
        int n=0;
        for(string s:words){
            int node=0;
            for(char c:s){
                if(nxt[node][c-'a']==0){
                    nxt.push_back(vector<int>(26));//we are keep pushing new nodes but won't exceed the size of trie
                    is_terminal.push_back(false);
                    nxt[node][c-'a']=++n;
                }
                node=nxt[node][c-'a'];
            }
            is_terminal[node]=true;
        }
        string answer="",so_far="";
        dfs(0,so_far,answer,nxt,is_terminal);
        return answer;
    }
    
};
