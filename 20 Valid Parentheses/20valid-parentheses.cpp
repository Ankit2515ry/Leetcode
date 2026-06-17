class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp={{')','('},{'}','{'},{']','['}};
        stack<char>st;
        for(auto it:s){
            if(it==')'||it=='}'||it==']'){
                char ch=mp[it];
                if(st.empty()||st.top()!=ch)return false;
                st.pop();
            }
            else st.push(it);
        }
        if(st.empty())return true;
        return false;
    }
};