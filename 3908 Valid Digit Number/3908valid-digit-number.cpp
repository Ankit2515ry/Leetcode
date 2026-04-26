class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        if(s[0]-'0'==x)return false;
        bool res=false;
        for(auto it:s){
            if(it-'0'==x)res=true;
        }
        return res;
    }
};