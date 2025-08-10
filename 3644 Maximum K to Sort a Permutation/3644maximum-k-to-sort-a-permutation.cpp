class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int res=(1<<30)-1;
        int f=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                res&=nums[i];
                f=1;
            }
        }
        if(f)return res;
        return 0;
    }
};