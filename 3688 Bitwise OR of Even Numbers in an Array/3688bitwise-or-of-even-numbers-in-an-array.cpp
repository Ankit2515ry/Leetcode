class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n=nums.size();
        bool f=false;
        int res=0;
        for(auto &it:nums){
            if(it%2==0)res|=it;
        }
        return res;
    }
};