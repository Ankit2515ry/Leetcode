class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int buy,vector<int>& prices){
        int n=prices.size();
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            int buynow=-prices[i]+solve(i+1,0,prices);
            int skip=solve(i+1,1,prices);
            profit=max(buynow,skip);
        }else{
            int sellnow=prices[i]+solve(i+2,1,prices);
            int skip=solve(i+1,0,prices);
            profit=max(sellnow,skip);
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return solve(0,1,prices);
    }
};