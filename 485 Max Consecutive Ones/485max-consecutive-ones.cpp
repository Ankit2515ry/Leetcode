class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //O(n) time complexity two pointer approach sliding window approach
        int res=0;
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                res=max(res,i-j);
                j=i+1;
            }
        }
        res=max(res,n-j);
        return res;
    }
};