class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int res=0;
        int n=nums.size();
        if(k==0)return n;
        if(k>=n)return res;
        sort(nums.begin(),nums.end());
        int a=nums[n-k];
        int i=0;
        for(i;i<n;i++){
            if(nums[i]<a)res++;
        }
        return res;
    }
};