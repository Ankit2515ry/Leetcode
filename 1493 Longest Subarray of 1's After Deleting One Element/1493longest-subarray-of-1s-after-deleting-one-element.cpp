class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res=0;
        int count0=0;
        int pre=0;
        int count=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                temp=0;
                count++;
                res=max(res,count+pre);
            }else{
                count0++;
                temp++;
                if(temp<2){
                    pre=count;
                    count=0;   
                }
                else{
                    pre=0;
                    count=0;
                }
            }
        }
        if(count0==0)return nums.size()-1;
        return res;
    }
};