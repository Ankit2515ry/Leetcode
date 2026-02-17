class Solution {
public:
    vector<vector<long long>>dp;
    long long solve(int i,int pre,vector<int>& nums, vector<int>& colors){
        int n=nums.size();
        if(i==n)return 0;
        if(dp[i][pre]!=-1)return dp[i][pre];
        long long a=0,b=0;
        if(i==0){
            a=nums[i]+solve(i+1,1,nums,colors);
            b=solve(i+1,0,nums,colors);
        }
        else{
            if(colors[i-1]==colors[i]&&pre==1){
                a=solve(i+1,0,nums,colors);
            }else{
                a=nums[i]+solve(i+1,1,nums,colors);
            }
            b=solve(i+1,0,nums,colors);
        }
        return dp[i][pre]=max(a,b);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        dp.assign(n,vector<long long>(2,-1));
        return solve(0,0,nums,colors);
    }
};