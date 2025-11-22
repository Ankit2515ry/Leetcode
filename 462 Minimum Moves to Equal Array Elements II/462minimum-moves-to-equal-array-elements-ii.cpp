class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        if(n%2!=0){
            int mid=nums[n/2];
            for(auto &it:nums){
                res+=abs(mid-it);
            }
        }else{
            int mid1=nums[n/2];
            int mid2=nums[n/2-1];
            int temp=0;
            for(auto &it:nums){
                res+=abs(mid1-it);
            }
            for(auto &it:nums){
                temp+=abs(mid2-it);
            }
            res=min(res,temp);
        }
        return res;
    }
};