class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int t) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int f=0;
            for(int j=i;j<n;j++){
                if(nums[j]==t)f++;
                if(f>(j-i+1)/2)res++;
            }
        }
        return res;
    }
};