class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>temp(nums.size(),0);
        int n=nums.size();
        if(n==1)return nums;
        temp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            temp[i]=max(temp[i+1],nums[i]);
        }
        int ma=nums[0];
        vector<int>res;
        res.push_back(ma);
        for(int i=1;i<n-1;i++){
            if(nums[i]>ma||nums[i]>temp[i+1]){
                res.push_back(nums[i]);
            }
            ma=max(ma,nums[i]);
        }
        res.push_back(nums[n-1]);
        return res;
    }
};