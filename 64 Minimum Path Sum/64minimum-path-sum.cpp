class Solution {
public:
    int n=0;
    int m=0;
    int inf=1e9;
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i>=n||j>=m)return inf;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==n-1&&j==m-1)return dp[i][j]=grid[n-1][m-1];
        int a=solve(i+1,j,grid);
        int b=solve(i,j+1,grid);
        int mini=grid[i][j]+min(a,b);
        return dp[i][j]=mini;
    }
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,grid);
    }
};

// class Solution {
// public:
//     //int res=INT_MAX;
//     vector<vector<int>>dp;
//     int solve(int i,int j,vector<vector<int>>&grid){
//         int n=grid.size();
//         int m=grid[0].size();
//         if(i>=n||j>=m)return INT_MAX;
//         if(i==n-1&&j==m-1){
//             return grid[i][j];
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
//         int d=solve(i+1,j,grid);
//         int r=solve(i,j+1,grid);
//         return dp[i][j]=grid[i][j]+min(d,r);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         dp.assign(n,vector<int>(m,0));
//         dp[0][0]=grid[0][0];
//         for(int i=1,j=0;i<n;i++){
//             dp[i][j]=dp[i-1][j]+grid[i][j];
//         }
//         for(int i=0,j=1;j<m;j++){
//             dp[i][j]=dp[i][j-1]+grid[i][j];
//         }
//         for(int i=1;i<n;i++){
//             for(int j=1;j<m;j++){
//                 dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[n-1][m-1];
//         //return solve(0,0,grid);
//         //return res;
//     }
// };