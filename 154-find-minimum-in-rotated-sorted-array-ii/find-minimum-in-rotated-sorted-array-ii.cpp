class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(r-l)/2+l;
            if(nums[r]<nums[mid]){
                l=mid+1;
            }else if(nums[l]>nums[mid]){
                r=mid;
                l++;
            }else{
                r--;
            }
        }
        return nums[l];
    }
};