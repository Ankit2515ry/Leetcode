class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        // if(n==1)return 1;
        // int res=1;
        // int temp=1;
        // bool f=true;
        // for(int i=1;i<n-1;i++){
        //     if(nums[i]>=nums[i-1]){
        //         temp++;
        //     }else if(f&&(i==n-1)||nums[i-1]<=nums[i+1]){
        //         temp++;
        //         f=false;
        //     }else{
        //         res=max(res,temp);
        //         temp=1;
        //         f=true;
        //     }
        //     res=max(res,temp);
        // }
        // return res;
        vector<int>l(n,1);
        vector<int>r(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1])l[i]=l[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1])r[i]=r[i+1]+1;
        }
        int res=max(l[0],r[n-1]);
        for(int i=0;i<n;i++){
            res=max({res,l[i],r[i]});
            if(i>0) res=max({res,l[i-1]+1});
            if(i<n-1) res=max({res,r[i+1]+1});
            if(i>0 && i<n-1 && nums[i-1]<=nums[i+1]){
                res=max(res,l[i-1]+r[i+1]+1);
            }
        }
        return res;
    }
};