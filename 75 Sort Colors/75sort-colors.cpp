class Solution {
public:
    void sortColors(vector<int>& nums) {

        // two-pass algorithm

        // vector<int>f(3,0);
        // for(auto &it:nums)f[it]++;
        // int i=0;
        // int v=0;
        // for(auto it:f){
        //     while(it--){
        //         nums[i]=v;
        //         i++;
        //     }
        //     v++;
        // }

        int n=nums.size();
        int l=0;
        int m=0;
        int r=n-1;
        while(m<=r){
            if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }else if(nums[m]==1)m++;
            else {
                swap(nums[m],nums[r]);
                r--;
            }
        }

    }
};