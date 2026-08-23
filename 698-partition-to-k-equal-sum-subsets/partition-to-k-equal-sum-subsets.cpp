class Solution {
public:
    int sum=0;
    int kk;
    vector<vector<int>>dp;
    bool solve(vector<int>& nums,int mask,int k,int s){
        int n=nums.size();
        if(k>kk)return false;
        if(mask==(1<<n)-1){
            if(k==kk&&s==0)return true;
            return false;
        }
        if(dp[mask][k]!=-1)return dp[mask][k];
        bool res=false;
        for(int i=0;i<n;i++){
            if(!((mask>>i)&1)){
                if(s+nums[i]==sum){
                    res|=solve(nums,mask|(1<<i),k+1,0);
                }else if(s+nums[i]<sum){
                    res|=solve(nums,mask|(1<<i),k,s+nums[i]);
                }
            }
        }
        return dp[mask][k]=res;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        for(auto it:nums)sum+=it;
        if(sum%k!=0)return false;
        sum/=k;
        kk=k;
        dp.assign((1<<(n+1)),vector<int>(k+1,-1));
        return solve(nums,0,0,0);
    }
};