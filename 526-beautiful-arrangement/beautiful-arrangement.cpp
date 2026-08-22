class Solution {
public:
    vector<int>dp;
    int solve(int n,int mask){
        int c=__builtin_popcount(mask);
        if(c==n)return 1;
        if(dp[mask]!=-1)return dp[mask];
        int res=0;
        for(int i=1;i<=n;i++){
            if(!((mask>>i)&1)){
                if((c+1)%i==0||i%(c+1)==0){
                    int nm=mask|(1<<i);
                    res+=solve(n,nm);
                }
            }
        }
        return dp[mask]=res;
    }
    int countArrangement(int n) {
        int sz=1<<(n+1);
        dp.assign(sz,-1);
        return solve(n,0);
    }
};