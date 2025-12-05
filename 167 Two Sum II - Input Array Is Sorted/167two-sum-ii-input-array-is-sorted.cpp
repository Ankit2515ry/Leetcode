class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int temp=target-nums[i];
            int l=i+1;
            int r=n-1;
            while(l<=r){
                int mid=((r-l)/2)+l;
                if(nums[mid]==temp)return {i+1,mid+1};
                else if(nums[mid]<temp)l=mid+1;
                else r=mid-1;
            }
        }
        return {-1,-1};
    }
};