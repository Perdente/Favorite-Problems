//https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1
set<char>st;
        for(auto ch:a)st.insert(ch);
        for(auto ch:a){
            st.erase(ch);
            if(st.empty())break;
            char c=*st.begin();
            if(c<ch){
                for(int i=0;i<(int)a.size();++i){
                    if(a[i]==ch)a[i]=c;
                    else if(a[i]==c)a[i]=ch;
                }
                break;
            }
        }
        return a;
