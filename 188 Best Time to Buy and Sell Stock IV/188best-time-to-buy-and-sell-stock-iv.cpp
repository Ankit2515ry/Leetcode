class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, int buy, int cap, vector<int>& prices) {
        int n = prices.size();
        if (i == n || cap == 0)
            return 0;
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;
        if (buy == 1) {
            int buyNow = -prices[i] + solve(i+1, 0, cap, prices);
            int skip   =  solve(i+1, 1, cap, prices);
            profit = max(buyNow, skip);
        }
        else {
            int sellNow = prices[i] + solve(i+1, 1, cap-1, prices);
            int skip    = solve(i+1, 0, cap, prices);
            profit = max(sellNow, skip);
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, k, prices);
    }
};
