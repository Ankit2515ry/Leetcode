class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //O(n2) time complexity
        // int res=INT_MIN;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int temp=1;
        //     for(int j=i;j<n;j++){
        //         temp*=nums[j];
        //         res=max(res,temp);
        //     }
        // }
        // return res;
        //O(n) time complexity two pass 
        int n=nums.size();
        int forward=1;
        int backword=1;
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            forward*=nums[i];
            res=max(res,forward);
            if(forward==0)forward=1;
        }
        for(int i=n-1;i>=0;i--){
            backword*=nums[i];
            res=max(res,backword);
            if(backword==0)backword=1;
        }
        return res;
        //O(n) time complexity
        // int pre=1;
        // int suf=1;
        // int res=INT_MIN;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(pre==0) pre=1;
        //     if(suf==0) suf=1;
        //     pre=pre*nums[i];
        //     suf=suf*nums[n-1-i];
        //     res=max(res,max(pre,suf));
        // }
        // return res;
    }
};