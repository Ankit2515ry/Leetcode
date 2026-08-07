class Solution {
public:
    bool canJump(vector<int>& nums) {
        int next=-1;
        int n=nums.size();
        if(n==1)return true;
        for(int i=0;i<n;i++){
            int curr=i+nums[i];
            next=max(next,curr);
            if(i!=n-1&&next==i)return false;   
        }
        return true;
    }
};