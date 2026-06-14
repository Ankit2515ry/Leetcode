class Solution {
public:
    bool checkGoodInteger(int n) {
        int s1=0;
        int s2=0;
        string s=to_string(n);
        for(auto it:s){
            int d=it-'0';
            s1+=d;
            s2+=d*d;
        }
        if(s2-s1>=50)return true ;
        return false;
    }
};