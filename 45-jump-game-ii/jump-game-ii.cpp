class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int res=1;
        int next=nums[0];
        int curr=1;
        while(curr<n){
            int maxi=next;
            if(next>=n-1)break;
            while(curr<n&&curr<=next){
                maxi=max(maxi,curr+nums[curr]);
                curr++;
            }
            res++;
            next=maxi;
        }
        return res;
    }
};