class Solution {
public:
    int passwordStrength(string password) {
        int res=0;
        unordered_set<char>st;
        for(auto it:password){
            if(!st.count(it)){
                if(it>='a'&&it<='z')res+=1;
                else if(it>='A'&&it<='Z')res+=2;
                else if(it>='0'&&it<='9')res+=3;
                else res+=5;
            }
             st.insert(it);   
        }
        return res;
    }
};