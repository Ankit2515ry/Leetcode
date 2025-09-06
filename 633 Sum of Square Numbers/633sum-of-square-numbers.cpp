class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int>st;
        int n=sqrt(c);
        for(int i=0;i<=n;i++){
            st.insert(i*i);
        }
        for(int i=0;i<=n;i++){
            if(st.find(c-(i*i))!=st.end())return true;
        }
        return false;
    }
};