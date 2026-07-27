class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=-1;
        int l=-1;
        int i=0;
        int j=nums.size()-1;
        if(j<0)return {f,l};
        while(i<=j){
            int mid=(j-i)/2+i;
            if(nums[mid]==target){
                f=mid;
                j=mid-1;
            }else if(nums[mid]<target){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        i=0;
        j=nums.size()-1;
        while(i<=j){
            int mid=(j-i)/2+i;
            if(nums[mid]==target){
                l=mid;
                i=mid+1;
            }else if(nums[mid]<target){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return {f,l};
    }
};