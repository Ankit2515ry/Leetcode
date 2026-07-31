class Solution {
public:
    int findPeakElement(vector<int>& nums) {    
        int n=nums.size();
        if(n==1)return 0;
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(r-l)/2+l;
            if(mid!=0&&mid!=n-1){
                if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])return mid;
                else if(nums[mid]<nums[mid-1]){
                    r=mid-1;
                }else if(nums[mid]<nums[mid+1]){
                    l=mid+1;
                }
            }else{
                if(mid==0&&nums[mid]>nums[mid+1])return mid;
                else if(mid==n-1&&nums[mid]>nums[mid-1])return mid;
                else if(mid==0)l=mid+1;
                else if(mid==n-1)r=mid-1;
            }
        }
        return -1;
    }
};