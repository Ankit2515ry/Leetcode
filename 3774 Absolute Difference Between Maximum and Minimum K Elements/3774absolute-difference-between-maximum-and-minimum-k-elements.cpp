class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ma=0;
        int mi=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;i++)mi+=nums[i];
        for(int i=n-1;k>0;i--,k--)ma+=nums[i];
        return abs(ma-mi);
    }
};