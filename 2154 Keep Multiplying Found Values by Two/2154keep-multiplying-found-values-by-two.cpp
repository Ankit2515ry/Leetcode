class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st;
        for(auto &it:nums)st.insert(it);
        int res=original;
        while(st.find(res)!=st.end()){
            res*=2;
        }
        return res;
    }
};