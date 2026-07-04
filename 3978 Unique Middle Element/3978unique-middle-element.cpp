class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int f=0;
        int n=nums.size();
        int v=nums[n/2];
        for(int i=0;i<n;i++){
            if(nums[i]==v)f++;
        }
        if(f==1)return true;
        return false;
    }
};