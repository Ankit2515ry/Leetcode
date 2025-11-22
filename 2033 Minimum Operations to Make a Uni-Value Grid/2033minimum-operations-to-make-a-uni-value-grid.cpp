class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>nums;
        for(auto &it:grid){
            for(auto &i:it)nums.push_back(i);
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        if(n%2!=0){
            int mid=nums[n/2];
            for(auto &it:nums){
                if(abs(mid-it)%x!=0)return -1;
                res+=abs(mid-it)/x;
            }
        }else{
            int mid1=nums[n/2];
            int mid2=nums[n/2-1];
            int temp=0;
            for(auto &it:nums){
                if(abs(mid1-it)%x!=0)return -1;
                res+=abs(mid1-it)/x;
            }
            for(auto &it:nums){
                if(abs(mid2-it)%x!=0)return -1;
                temp+=abs(mid2-it)/x;
            }
            res=min(res,temp);
        }
        return res;
    }
};