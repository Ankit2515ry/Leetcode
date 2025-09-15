class Solution {
public:
    int canBeTypedWords(string text, string b) {
        int res=0;
        bool f=true;
        unordered_set<char>st;
        for(auto &it:b)st.insert(it);
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if(f)res++;
                f=true;
            }else{
                if(st.find(text[i])!=st.end())f=false;
            }
            //cout<<res<<" ";
        }
        if(f)res++;
        //cout<<res<<" ";
        return res;
    }
};