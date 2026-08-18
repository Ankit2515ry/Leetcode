class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        // int n=nums.size();
        // for(int i=0;i<=n-k;i++){
        //     if(nums[i]<0)return false;
        //     for(int j=i+1;j<i+k;j++){
        //         nums[j]-=nums[i];
        //     }
        //     nums[i]=0;
        // }
        // for(int i=n-k+1;i<n;i++){
        //     if(nums[i]!=0)return false;
        // }
        // return true;

        int n=nums.size();
        vector<int>diff(n+1,0);
        int cd=0;
        for(int i=0;i<n;i++){
            cd+=diff[i];
            if(nums[i]<cd)return false;
            int r=nums[i]-cd;
            if(r>0){
                if(i+k>n)return false;
                cd+=r;
                diff[i+k]-=r;
            }
        }
        return true;
    }
};