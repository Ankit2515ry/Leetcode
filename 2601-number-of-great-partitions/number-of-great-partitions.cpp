class Solution {
public:
    int mod=1e9+7;
    int k;
    vector<vector<long long>>dp;
    long long solve(vector<int>& nums,int i,long long sum){
        int n=nums.size();
        if(i>=n)return 1;
        if(dp[i][sum]!=-1)return dp[i][sum];
        long long a=solve(nums,i+1,sum)%mod;
        long long b=0;
        if(sum+nums[i]<k){
            b=solve(nums,i+1,sum+nums[i])%mod;
        }
        return dp[i][sum]=(a+b)%mod;
    }
    int countPartitions(vector<int>& nums, int kk) {
        int n=nums.size();
        long long sum = 0;
        for(int it:nums)sum+=it;
        if(sum<2LL*kk)return 0;
        k=kk;
        dp.assign(n,vector<long long>(k+1,-1));
        long long sumless=solve(nums,0,0);
        long long sumall=1;
        for(int i=0;i<n;i++){
            sumall=(sumall*2)%mod;
        }
        long long sumgreat=(sumall-(2*sumless)%mod+mod)%mod;
        return sumgreat;
    }
};