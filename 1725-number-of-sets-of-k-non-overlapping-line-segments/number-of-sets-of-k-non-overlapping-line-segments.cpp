class Solution {
public:
    int mod=1e9+7;
    int dp[1005][1005][2];
    long long solve(int n,int k,int i,int c,int f){
        if(c==k&&f==0)return 1;
        if(i>=n-1){
            if(c==k)return 1;
            return 0;
        }
        if(dp[i][c][f]!=-1)return dp[i][c][f];
        long long res=0;
        if(f==0){
            res=(res+solve(n,k,i+1,c,0))%mod;
            res=(res+solve(n,k,i+1,c+1,1))%mod;
        }else{
            res=(res+solve(n,k,i+1,c,0))%mod;
            res=(res+solve(n,k,i+1,c,1))%mod;
            res=(res+solve(n,k,i+1,c+1,1))%mod;
        }
        return dp[i][c][f]=res;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,0,0,0);
    }
};