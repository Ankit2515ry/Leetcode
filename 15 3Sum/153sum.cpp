class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //O(n2) time and space complexity
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1])continue;
            int l=i+1;
            int r=n-1;
            int v=nums[i]*-1;
            while(l<r){
                if(nums[l]+nums[r]==v){
                    vector<int>temp={nums[i],nums[l],nums[r]};
                    res.push_back(temp);
                    while(l<r){
                        if(nums[l]==nums[l+1])l++;
                        else break;
                    }
                    l++;
                    while(l<r){
                        if(nums[r]==nums[r-1])r--;
                        else break;
                    }
                    r--;
                }else if(v>nums[l]+nums[r]){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return res;
    }
};