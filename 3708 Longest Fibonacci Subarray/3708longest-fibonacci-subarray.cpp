class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res=2;
        int n=nums.size();
        int temp=2;
        for(int i=1;i<n-1;i++){
            if(nums[i]+nums[i-1]==nums[i+1])temp++;
            else temp=2;
            res=max(res,temp);
        }
        return res;
    }
};