class Solution {
public:
    int findMin(vector<int>& nums) {
        int res=INT_MAX;
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(r-l)/2+l;
            res=min(res,nums[mid]);
            if(nums[l]<=nums[mid]&&nums[r]<=nums[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return res;
    }
};