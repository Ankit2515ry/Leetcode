class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res=0;
        int mi=INT_MAX;
        for(auto &it:nums)mi=min(mi,it);
        for(auto &it:nums)res+=it-mi;
        return res;
    }
};