class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char>st;
        int res=0;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
            if(st.size()==(i+1)%3)res++;
        }
        return res;
    }
};