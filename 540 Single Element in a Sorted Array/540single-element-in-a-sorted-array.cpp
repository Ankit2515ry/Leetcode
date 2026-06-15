class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //O(n) time complexity
        // int n=nums.size();
        // if(n==1)return nums[0];
        // for(int i=1;i<n;i+=2){
        //     if(nums[i]!=nums[i-1])return nums[i-1];
        // }
        // return nums[n-1];

        //O(n) time complexity
        // int res=0;
        // for(auto it:nums)res^=it;
        // return res;

        int n=nums.size();
        if(n==1)return nums[0];
        int l=0;
        int r=n-1;
        int mid=(r-l)/2+l;
        while(l<r){
            if(mid%2==1){
                mid--;
            }
            if(nums[mid]==nums[mid+1]){
                l=mid+2;
            }else{
                r=mid;
            }
            mid=(r-l)/2+l;
        }
        return nums[l];
    }
};