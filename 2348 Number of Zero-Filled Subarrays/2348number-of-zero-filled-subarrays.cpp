class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res=0;
        long long temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)temp++;
            else{
                res+=(temp*(temp+1))/2;
                temp=0;
            }
        }
        res+=(temp*(temp+1))/2;
        return res;
    }
};