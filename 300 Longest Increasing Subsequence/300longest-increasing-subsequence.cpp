class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>& nums){
        int n=nums.size();
        if(i==n)return 0;
        if(dp[i][j+1]!=-1)return dp[i][j+1];
        int a=solve(i+1,j,nums);
        int b=0;
        if(j==-1||nums[j]<nums[i]){
            b= 1+solve(i+1,i,nums);
        } 
        return dp[i][j+1]=max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        //vector<int> tails;
        // for (int x : nums) {
        //     auto it = lower_bound(tails.begin(), tails.end(), x);
        //     if (it == tails.end())
        //         tails.push_back(x);
        //     else
        //         *it = x;
        // }
        // return tails.size();
        int n=nums.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums);
    }
};