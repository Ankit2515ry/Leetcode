class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
        vector<int>pre;
        int mini=INT_MAX;
        for(auto &it:nums){
            mini=min(mini,it);
            pre.push_back(mini);
        }
        vector<int>pos;
        mini=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            pos.push_back(mini);
        }
        reverse(pos.begin(),pos.end());
        for(int i=1;i<n-1;i++){
            if(nums[i]>pre[i-1]&&nums[i]>pos[i+1])res=min(res,nums[i]+pre[i-1]+pos[i+1]);
        }
        if(res==INT_MAX)return -1;
        return res;
    }
};