class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>diff(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int sum=nums[i]+nums[n-i-1];
            int mini=min(nums[i],nums[n-i-1]);
            int maxi=max(nums[i],nums[n-i-1]);
            diff[1]+=2;
            diff[2*limit+1]-=2;
            diff[mini+1]-=1;
            diff[maxi+limit+1]+=1;
            diff[sum]-=1;
            diff[sum+1]+=1;
        }
        int res=INT_MAX;
        for(int i=1;i<diff.size()-1;i++){
            diff[i]+=diff[i-1];
            res=min(res,diff[i]);
        }
        return res;
    }
};